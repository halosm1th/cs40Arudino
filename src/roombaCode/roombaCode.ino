#include<SoftwareSerial.h>

int rxPin = 10;
int txPin = 11;
int ddPin = 5;

SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  Serial.begin(19200);
  delay(1000);
  Serial.println("Hello Dave");
  pinMode (ddPin, OUTPUT);
  Serial.println("Hello Dave, pinmod set");
    delay(1000);
  mySerial.begin(19200);
  Serial.println("Hello Dave, serial began");
  delay(1000);
  Serial.println("Hello Dave, there was a delay");
  if (mySerial.available())
    Serial.println(mySerial.read());
  else
    Serial.println("test");
  Serial.println("Hello Dave, we read from serial!");
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(2000);
  Serial.println("I'm awake");
   delay(1000);


   //Setting to safe mode
  mySerial.write(128  ); //Starting roomba
  delay(1000);
  mySerial.write(131); //Safemode
  delay(1000);
  Serial.println("Going into safemode");
  delay(1000);
  codeSong(); //Code the song into memoryM
  //Play song.
   swrite(141); //playing the song
  Serial.println("Writing to play");
  delay(1000);

  //Drive straight
  Serial.println("Driving striaght");
  for(int i = 0; i < 10; i++){
    driveStraight(100);
  }
  delay(100);
  Serial.println("Stopping");
    driveStraight(0);
  //endofCode();

}

void codeSong(){
  Serial.println("Wrote opcode for writing song");
  swrite(140);
  Serial.println("Writing song num");
  swrite(1);
  Serial.println("WRiting song len");
  swrite(16);
  Serial.println("Wriring notes");
  for(int i = 64; i < 80; i++){
    playNote(i,255);
  }
}


void driveStraight(int vel){
  delay(100);
  mySerial.write(137);
  delay(100);
  sendHighLow(vel);
  delay(100);
  mySerial.write(128);
  delay(100);
  mySerial.write(1);
}
void drive(int vel, int rad){
  mySerial.write(137);
  sendHighLow(vel);
  sendHighLow(rad);
}
void sendHighLow(int send) {
  mySerial.write(highByte(send));
  delay(100);
  mySerial.write(lowByte(send));
  delay(100);
}


void playNote(int note, int len){
  swrite(note);
  swrite(len);
}

void swrite(int message){
  mySerial.write(message);
  delay(100);
}

 void endofCode(){
  mySerial.write(143);
  delay(100);
}

void loop() {
  // Serial.println("Hello Dave");

}

