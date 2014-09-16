
const int pressurePin = A0;  // Analog input pin that the potentiometer is attached to

const int mode_0_pin = 7;
const int mode_1_pin = 8;
const int mode_2_pin = 9;
const int channel_0_pin = 5;
const int channel_1_pin = 6;
const int note_0_pin = 4;
const int note_1_pin = 3;
const int note_2_pin = 2;
const int note_3_pin = 0;
const int note_4_pin = 1;
const byte playNote = 0x90;
const byte afterTouch = 0xD0;
const byte cc_windController = 0x02;
const byte cc_volume = 0x07;
const byte cc = 0xB0;
const byte vMax = 0x7F;
const byte cOne = 0xA;
const byte cTwo = 0xB;
const byte channelOne = 0;
const byte channelTwo = B10;
const byte pMin = 60;
const unsigned char notes[] = {24, 25, 26, 27, 28, 29, 29, 30, 31, 32, 33, 34, 35, 36, 36, 37, 38, 39, 40, 41, 41, 42, 43, 44, 45, 46, 47, 48, 48, 49, 50, 51, 52, 53, 53, 54, 55, 56, 57, 58, 59, 60, 60, 61, 62, 63, 64, 65, 65, 66, 67, 68, 69, 70, 71, 72, 72, 73, 74, 75, 76, 77, 77, 78, 79, 80, 81, 82, 83, 84, 84, 85, 86, 87, 88, 89, 89, 90, 91, 92, 93, 94, 95, 96, 96, 97, 98, 99, 100, 101, 101, 102, 103, 104, 105, 106, 107};
const unsigned char scaleOffset = 28;
byte oldCOne, newCOne,
     oldCTwo, newCTwo;
    

int sensorValue = 0;
int t_wait = 39;
int delta_t;

unsigned long t_last;

byte oldP = 0,
     newP = 0,
     buttons,
     channel,
     channelSelect,
     modeSelect,
     newNote,
     oldNote;

void setup() {
  Serial.begin(9600); 
  while (!Serial) ;
  
  pinMode(mode_0_pin, INPUT_PULLUP);
  pinMode(mode_1_pin, INPUT_PULLUP);
  pinMode(note_0_pin, INPUT_PULLUP);
  pinMode(note_1_pin, INPUT_PULLUP);
  pinMode(note_2_pin, INPUT_PULLUP);
  pinMode(note_3_pin, INPUT_PULLUP);
  pinMode(note_4_pin, INPUT_PULLUP);
  pinMode(channel_0_pin, INPUT_PULLUP);
  pinMode(channel_1_pin, INPUT_PULLUP);

  newNote = notes[0];
  oldNote = notes[0];
  channel = 0;
  t_last = millis();
}

void loop() {  
  newP = readPressure(pressurePin);
  if (newP != oldP){
    delta_t = millis() - t_last;
    if (newP == 0){
      sendNote(channel, getNote(newNote), 0);
      sendCC(channel, cc_volume, 0);
    }
    if (oldP == 0){
      sendNote(channel, getNote(newNote), vMax);
    }
    else if (delta_t >= t_wait){
      sendCC(channel, cc_volume, newP);
      t_last = millis();
    }
    oldP = newP;
  }
  newNote = readNote();
  channel = readChannel();
  if (newNote != oldNote){
    sendNote(channel, getNote(oldNote), 0);
    sendNote(channel, getNote(newNote), vMax);
    oldNote = newNote;
  }
}

byte readPressure(int pin){
 sensorValue = analogRead(pin);
 if (sensorValue <= pMin){return 0;}
 else
 {return min(127, sensorValue * 0.9 - pMin);}
}

int readNote(){
  buttons = 0;
  if (digitalRead(note_0_pin) == LOW){buttons += 1;}
  if (digitalRead(note_1_pin) == LOW){buttons += 2;}
  if (digitalRead(note_2_pin) == LOW){buttons += 4;}
  if (digitalRead(note_3_pin) == LOW){buttons += 8;}
  if (digitalRead(note_4_pin) == LOW){buttons += 16;}
  return buttons;
}

byte readMode(){
  buttons = 0;
  if (digitalRead(mode_0_pin) == LOW){buttons += 1;}
  if (digitalRead(mode_1_pin) == LOW){buttons += 2;}
  return buttons;
}

byte readChannel(){
  buttons = 0;
  if (digitalRead(channel_0_pin) == LOW){buttons += 1;}
  if (digitalRead(channel_1_pin) == LOW){buttons += 2;}
  return buttons;
}

int getNote(int buttonState){
  return notes[buttonState + scaleOffset];
  //return buttonState + 47;
}

byte readController(int pin){
  return map(analogRead(pin), 0, 1023, 0, 127);
}
    
void sendNote(byte channel, byte note, byte velocity){
  Serial.write(playNote + channel);
  Serial.write(note);
  Serial.write(velocity);
}

void sendCC(byte channel, byte controller, byte value){
  Serial.write(cc + channel);
  Serial.write(controller);
  Serial.write(value);
}

void sendAftertouch(byte channel, byte pressure){
  Serial.write(afterTouch + channel);
  Serial.write(pressure);
}
