#include <MIDI.h>
// defining pin assignments as macros to save precious RAM for variables
#define PRESSURE_PIN A0
#define OCTAVE_PIN A1
#define NOTE_0_PIN 4
#define NOTE_1_PIN 3
#define NOTE_2_PIN 2
#define NOTE_3_PIN 0

// defining constants for MIDI commands (First transmitted byte)
const byte playNote = 0x90;   // Note on
const byte pitchBend = 0x70;  // Pitch bend
const byte cc = 0xB0;         // Continous Controller
// ...for MIDI parameters (Second and third transmitted byte)
const byte cc_volume = 0x07;  // Selects channel volume (coarse) as CC target
const byte cc_detune = 0x2D;
const byte midiMax = 0x7F;    // The highest possible parameter value (127 or 0b1111111)
const byte midiMin = 0;       // A zero, just giving it a fancy name here

const byte pMin = 48;         // The minimal pressure the sensor has to pick up to trigger a note
// The pressureCurve is an array thatallows to map the linear readings of the sensor to a non linear
// increase of loudness. It is also useful to increase the usable pressure range
const byte pressureCurve[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int lPressureCurve = 259; // The size of the pressureCurve array. Has to be provided to avoid index errors
// Detunes is a second pressure curve that can be mapped to any continous controller
// it gives 50% output for most of the time with linear increase at the upper end.
// This can be used to modulate a synthesizer depending on the applied pressure
const signed char detunes[] = {63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94};

// the notes array takes care of mapping the 128 notes of the MIDI scale to the one the nibbleTronic uses
// note that c and f appear twice resulting in 14 notes per octave
const signed char notes[] = {0, 0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 29, 30, 31, 32, 33, 34, 35, 36, 36, 37, 38, 39, 40, 41, 41, 42, 43, 44, 45, 46, 47, 48, 48, 49, 50, 51, 52, 53, 53, 54, 55, 56, 57, 58, 59, 60, 60, 61, 62, 63, 64, 65, 65, 66, 67, 68, 69, 70, 71, 72, 72, 73, 74, 75, 76, 77, 77, 78, 79, 80, 81, 82, 83, 84, 84, 85, 86, 87, 88, 89, 89, 90, 91, 92, 93, 94, 95, 96, 96, 97, 98, 99, 100, 101, 101, 102, 103, 104, 105, 106, 107, 108, 108, 109, 110, 111, 112, 113, 113, 114, 115, 116, 117, 118, 119, 120, 120, 121, 122, 123, 124, 125, 125, 126, 127};

const byte scaleOffset = 28; // we start at the second octave
const byte octaves[] = {0, 14, 28, 42, 56, 70, 84, 98, 112}; // nine octaves
const byte octaveRange = 4; // This is the number of octaves that make up the range of the octave  slider

int sensorValue = 0;
int t_wait = 39;
int delta_t;
int requiredDeltaP = 3;

unsigned long t_last, now;

//MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, din_5);
MIDI_CREATE_DEFAULT_INSTANCE()
void sendCC(byte channel, byte controller, byte value) {
  Serial1.write(cc + channel);
  Serial1.write(controller);
  Serial1.write(value);
}

class pressureControlledMIDI{
  private:
  int _oldValue = 0, _newValue = 0;
  int _noiseTolerance;
  byte _CC_target;
  byte *_values;
  int _nValues;
  int _threshold, _upperLimit;
  

  public:
  midi::MidiInterface<HardwareSerial> MIDI;
  pressureControlledMIDI(int threshold,\
                         byte CC_target,\
                         byte values[],\
                         int nValues,\
                         int noiseTolerance,\
                         bool activateMidi = false){
    _noiseTolerance = noiseTolerance;
    _CC_target = CC_target;
    _values = values;
    _nValues = nValues;
    _threshold = threshold;
    if(activateMidi){
      MIDI = midi::MidiInterface<HardwareSerial>((HardwareSerial&)Serial1);
    }
  }
  
  bool update(int pressure){
    int pressureIndex = constrain(pressure - _threshold, 0, _nValues - 1);
    _newValue = _values[pressureIndex];
    signed char delta = abs(_oldValue - _newValue);
    Serial.print(_oldValue);
    Serial.print("\t");
    Serial.print(_newValue);
    Serial.print("\t");
    Serial.println(delta);
    
    if(delta > _noiseTolerance){
      _oldValue = _newValue;
      return true;
    }else{
      return false;
    }
  }
  void send(){
    MIDI.sendControlChange(_CC_target, _newValue, 1);
  }  
};

byte buttons,
     channel,
     channelSelect,
     modeSelect,
     newNote,
     oldNote,
     oldCOne, newCOne,
     oldCTwo, newCTwo, octaveOffset;

int readNote() {
  buttons = 0;
  if (digitalRead(NOTE_0_PIN) == LOW) {
    buttons += 1;
  }
  if (digitalRead(NOTE_1_PIN) == LOW) {
    buttons += 2;
  }
  if (digitalRead(NOTE_2_PIN) == LOW) {
    buttons += 4;
  }
  if (digitalRead(NOTE_3_PIN) == LOW) {
    buttons += 8;
  }
  return buttons + scaleOffset + getOctave();
}

byte getOctave() {
  octaveOffset = 0;
  int sliderValue = analogRead(OCTAVE_PIN);
  byte octaveIndex = map(sliderValue, 0, 1023, 0, octaveRange);
  return octaves[octaveIndex];
}

int getNote(int buttonState) {
  return notes[buttonState + scaleOffset + getOctave()];
}

byte readController(int pin) {
  return map(analogRead(pin), 0, 1023, 0, 127);
}

void sendNote(byte channel, byte note, byte velocity) {
  Serial1.write(playNote + channel);
  Serial1.write(note);
  Serial1.write(velocity);
}

void sendPitchBend(byte channel, int sensorOutput) {
  int amount = map(sensorOutput, 0, 1023, 0, 16384);
  byte lsb = amount & 0b1111111;
  byte msb = amount >> 7;
  Serial1.write(pitchBend + channel);
  Serial1.write(lsb);
  Serial1.write(msb);
}

pressureControlledMIDI volume(pMin, cc_volume, pressureCurve, lPressureCurve, 2, din_5);
pressureControlledMIDI detune(pMin, cc_detune, detunes, lPressureCurve, 0, din_5);

void setup() {
  Serial.begin(9600);
  din_5.begin();
  while (!Serial);

  pinMode(NOTE_0_PIN, INPUT_PULLUP);
  pinMode(NOTE_1_PIN, INPUT_PULLUP);
  pinMode(NOTE_2_PIN, INPUT_PULLUP);
  pinMode(NOTE_3_PIN, INPUT_PULLUP);
  pinMode(OCTAVE_PIN, INPUT);
  pinMode(PRESSURE_PIN, INPUT);

  newNote = notes[0];
  oldNote = notes[0];
  channel = 0;
  t_last = millis();
}

void loop() {
  now = millis();
  int pressure = analogRead(PRESSURE_PIN);
  if(volume.update(pressure)){
    volume.send();
  }
  /*if(detune.update(pressure)){
    detune.send();
  }*/

  newNote = readNote();
  if (newNote != oldNote) {
    din_5.sendNoteOn(notes[oldNote], 0, channel);
    din_5.sendNoteOn(notes[newNote], midiMax, channel);
    oldNote = newNote;
  }
}


