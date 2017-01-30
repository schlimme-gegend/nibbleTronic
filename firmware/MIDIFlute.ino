// defining pin assignments as macros to save precious RAM for variables
#define PRESSURE_PIN A0
#define OCTAVE_PIN A1
#define NOTE_0_PIN 4
#define NOTE_1_PIN 3
#define NOTE_2_PIN 2
#define NOTE_3_PIN 0
#define SLIDER_0_PIN A11
#define SLIDER_1_PIN A5
#define JOYSTICK_X_PIN A2
#define JOYSTICK_Y_PIN A3

// defining constants for MIDI commands (First transmitted byte)
const byte playNote = 0x90;   // Note on
const byte pitchBend = 0x70;  // Pitch bend
const byte cc = 0xB0;         // Continous Controller
// ...for MIDI parameters (Second and third transmitted byte)
const byte cc_volume = 0x07;  // Selects channel volume (coarse) as CC target
const byte cc_expr = 0xB;     // Selects Expression as CC target This is interpreted as volume by the Volca Bass
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
const signed char notes[] = {0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 29, 30, 31, 32, 33, 34, 35, 36, 36, 37, 38, 39, 40, 41, 41, 42, 43, 44, 45, 46, 47, 48, 48, 49, 50, 51, 52, 53, 53, 54, 55, 56, 57, 58, 59, 60, 60, 61, 62, 63, 64, 65, 65, 66, 67, 68, 69, 70, 71, 72, 72, 73, 74, 75, 76, 77, 77, 78, 79, 80, 81, 82, 83, 84, 84, 85, 86, 87, 88, 89, 89, 90, 91, 92, 93, 94, 95, 96, 96, 97, 98, 99, 100, 101, 101, 102, 103, 104, 105, 106, 107, 108, 108, 109, 110, 111, 112, 113, 113, 114, 115, 116, 117, 118, 119, 120, 120, 121, 122, 123, 124, 125, 125, 126, 127, 127};

const byte scaleOffset = 28; // we start at the second octave
const byte octaves[] = {0, 14, 28, 42, 56, 70, 84, 98, 112}; // nine octaves
const byte octaveRange = 4; // This is the number of octaves that make up the range of the octave  slider
const byte baseOctave = 2;  // The lowest selectable octave

const byte slidertolerance = 3;       // Noise Reduction for sliders to prevent joystick noise in center position

void sendCC(byte channel, byte controller, byte value) {
  Serial1.write(cc + channel);
  Serial1.write(controller);
  Serial1.write(value);
  Serial.print("CC");
  Serial.print("\t");
  Serial.print(controller);
  Serial.print("\t");
  Serial.println(value);
}

class pressureControlledMIDI{
  /* This object reads analog values from the pressure sensor and maps them
   *  to a member of the values array.
   *  parameters for the cotr are:
   *  threshold: A minimal pressure reading that has to be exceeded to trigger
   *  CC_target: The continous controller that is to be affected. 
   *             Channel volume or expression are typical values
   *  values[]:  The array of output values
   *  nValues:   The length of the value array
   *  noiseTolerance: The minimal change in output that is required to send a new message
   *                  reduces the number of messages sent but might introduce latency
   */
  private:
  int _oldValue = 0, _newValue = 0;
  int _noiseTolerance;
  byte _CC_target;
  byte *_values;
  int _nValues;
  int _threshold, _upperLimit;

  public:
  pressureControlledMIDI(int threshold,\
                         byte CC_target,\
                         byte values[],\
                         int nValues,\
                         int noiseTolerance){
    _noiseTolerance = noiseTolerance;
    _CC_target = CC_target;
    _values = values;
    _nValues = nValues;
    _threshold = threshold;
  }
  
  void update(int pressure, byte channel){
    int pressureIndex = constrain(pressure - _threshold, 0, _nValues - 1);
    _newValue = _values[pressureIndex];
    signed char delta = abs(_oldValue - _newValue);
    
    if(delta > _noiseTolerance){
      _oldValue = _newValue;
      sendCC(channel, _CC_target, _newValue);
    }
  }
};

class Slider{
  /* This object allows to map slider input to a continous controller
   *  parameters of ctor:
   *  pin: The input pin to which the slider is connected
   *  CC_target: The CC that is being affected
   *  invert: set true for reversing the direction of a slider. Default is 'false'
   */
  private:
    int _pin, oldValue, newValue;
    byte _channel;
    byte _CC_target;
    bool _invert;
  public:
    Slider(int pin, byte CC_target, bool invert = false){
      _pin = pin;
      _CC_target = CC_target;
      _invert = invert;
      pinMode(pin, INPUT);
    }
    void update(byte channel){
      newValue = analogRead(_pin);
      if (newValue != oldValue){
        signed char sliderdelta = abs(oldValue - newValue);
        if(sliderdelta > slidertolerance){
        if(_invert){
          sendCC(channel, _CC_target, map(newValue, 0, 1023, 127, 0));
        }else{
          sendCC(channel, _CC_target, map(newValue, 0, 1023, 0, 127));
        }
        oldValue = newValue;
      }
    }
    }
};


byte getOctave(byte start = 0) {
  byte end = start + octaveRange - 1;
  int sliderValue = analogRead(OCTAVE_PIN);
  byte octaveIndex = map(sliderValue, 0, 1000, start, end);
  return octaves[octaveIndex];
}

byte readNote(byte startOctave) {
  byte buttons = 0;
  if (digitalRead(NOTE_0_PIN) == HIGH) {
    buttons += 1;
  }
  if (digitalRead(NOTE_1_PIN) == HIGH) {
    buttons += 2;
  }
  if (digitalRead(NOTE_2_PIN) == HIGH) {
    buttons += 4;
  }
  if (digitalRead(NOTE_3_PIN) == HIGH) {
    buttons += 8;
  }
  int index = buttons + scaleOffset + getOctave(startOctave);
  return notes[index];
}

void sendNote(byte channel, byte note, byte velocity) {
  Serial1.write(playNote + channel);
  Serial1.write(note);
  Serial1.write(velocity);
  Serial.print("note");
  Serial.print("\t");
  Serial.print(note);
  Serial.print("\t");
  Serial.println(velocity);
}

void sendPitchBend(byte channel, int sensorOutput) {
  int amount = map(sensorOutput, 0, 1023, 0, 16384);
  byte lsb = amount & 0b1111111;
  byte msb = amount >> 7;
  Serial1.write(pitchBend + channel);
  Serial1.write(lsb);
  Serial1.write(msb);
}

byte channel,
     newNote,
     oldNote;
     
pressureControlledMIDI volume(pMin, cc_volume, pressureCurve, lPressureCurve, 2);
pressureControlledMIDI detune(pMin, cc_detune, detunes, lPressureCurve, 0);
//Slider leftSlider(SLIDER_0_PIN, 1);
//Slider rightSlider(SLIDER_1_PIN, 16);
Slider joyX(JOYSTICK_X_PIN, 1);
Slider joyY(JOYSTICK_Y_PIN, 2);

void setup() {
  Serial.begin(9600);
  Serial1.begin(31250);
  analogReference(DEFAULT);
  pinMode(NOTE_0_PIN, INPUT_PULLUP);
  pinMode(NOTE_1_PIN, INPUT_PULLUP);
  pinMode(NOTE_2_PIN, INPUT_PULLUP);
  pinMode(NOTE_3_PIN, INPUT_PULLUP);
  pinMode(OCTAVE_PIN, INPUT);
  pinMode(PRESSURE_PIN, INPUT);

  newNote = notes[0];
  oldNote = notes[0];
  channel = 0;
}

void loop() {
  int pressure = analogRead(PRESSURE_PIN);
  volume.update(pressure, channel);
  detune.update(pressure, channel);
  //leftSlider.update(channel);
  //rightSlider.update(channel);
  joyX.update(channel);
  joyY.update(channel);
  
  newNote = readNote(baseOctave);
  if (newNote != oldNote) {
    sendNote(channel, notes[oldNote], 0);
    sendNote(channel, notes[newNote], midiMax);
    oldNote = newNote;
  }
}

