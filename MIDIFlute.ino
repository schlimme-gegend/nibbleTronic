
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
const int note_4_pin = 13;
const byte noise = 0xA;
const byte playNote = 0x90;
const byte afterTouch = 0xD0;
const byte cc_windController = 0x02;
const byte cc_volume = 0x07;
const byte cc_expression = 0x0b;
const byte cc = 0xB0;
const byte vMax = 0x7F;
const byte cOne = 0xA;
const byte cTwo = 0xB;
const byte channelOne = 0;
const byte channelTwo = B10;
const byte pMin = 12;
const byte pressureCurve[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
const int lPressureCurve = 259;
const unsigned char notes[] = {24, 25, 26, 27, 28, 29, 29, 30, 31, 32, 33, 34, 35, 36, 36, 37, 38, 39, 40, 41, 41, 42, 43, 44, 45, 46, 47, 48, 48, 49, 50, 51, 52, 53, 53, 54, 55, 56, 57, 58, 59, 60, 60, 61, 62, 63, 64, 65, 65, 66, 67, 68, 69, 70, 71, 72, 72, 73, 74, 75, 76, 77, 77, 78, 79, 80, 81, 82, 83, 84, 84, 85, 86, 87, 88, 89, 89, 90, 91, 92, 93, 94, 95, 96, 96, 97, 98, 99, 100, 101, 101, 102, 103, 104, 105, 106, 107};
const byte detunes[] = {63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94};
const unsigned char scaleOffset = 28;


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
     oldNote,
     oldCOne, newCOne,
     oldCTwo, newCTwo, octaveOffset;
    

void setup() {
  Serial1.begin(31250); 
  while (!Serial1) ;
  
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
  channel = readChannel();
  if (newP != oldP){
    if (newP == 0){
      sendNote(channel, notes[newNote], 0);
      sendExpression(channel, newP);
      oldP = 0;
    }
    else if (oldP == 0){
      sendNote(channel, notes[newNote], vMax);
      oldP = newP;
    }
    else if (millis() - t_last > t_wait){
      sendExpression(channel, newP);
      t_last = millis();
    }
  }
  newNote = readNote();
  if (newNote != oldNote){
    sendNote(channel, notes[oldNote], 0);
    sendNote(channel, notes[newNote], vMax);
    oldNote = newNote;
  }
}

byte readPressure(int pin){
 sensorValue = analogRead(pin);
 if (sensorValue <= pMin){return 0;}
 else
 {return pressureCurve[min(lPressureCurve, int(sensorValue - pMin))];}
}

int readNote(){
  buttons = 0;
  if (digitalRead(note_0_pin) == LOW){buttons += 1;}
  if (digitalRead(note_1_pin) == LOW){buttons += 2;}
  if (digitalRead(note_2_pin) == LOW){buttons += 4;}
  if (digitalRead(note_3_pin) == LOW){buttons += 8;}
  if (digitalRead(note_4_pin) == LOW){buttons += 16;}
  return buttons + scaleOffset + getOctave();
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
  //if (digitalRead(channel_1_pin) == LOW){buttons += 2;}
  return buttons;
}

byte getOctave(){
  octaveOffset = 0;
  if (digitalRead(mode_0_pin) == LOW){octaveOffset += 14;}
  if (digitalRead(channel_1_pin) == LOW){octaveOffset += 28;}
  return octaveOffset;
}

int getNote(int buttonState){
  return notes[buttonState + scaleOffset + getOctave()];
  //return buttonState + 47;
}

byte readController(int pin){
  return map(analogRead(pin), 0, 1023, 0, 127);
}
    
void sendNote(byte channel, byte note, byte velocity){
  Serial1.write(playNote + channel);
  Serial1.write(note);
  Serial1.write(velocity);
}

void sendCC(byte channel, byte controller, byte value){
  Serial1.write(cc + channel);
  Serial1.write(controller);
  Serial1.write(value);
}

void sendCVolume(byte channel, byte pressure){
  sendCC(channel, cc_volume, pressure);
  oldP = pressure;
}

void sendExpression(byte channel, byte pressure){
  sendCC(channel, cc_expression, pressure);
  sendCC(channel, 45, detunes[pressure]);
  oldP = pressure;
}

void sendAftertouch(byte channel, byte pressure){
  Serial1.write(afterTouch + channel);
  Serial1.write(pressure);
}
