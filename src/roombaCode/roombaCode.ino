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
  mySerial.write(128);
  delay(1000);
  mySerial.write(131);
  delay(1000);
  Serial.println("Going into safemode");
  delay(1000);
  codeSong();
   swrite(141);
  Serial.println("Writing to play");
  swrite(1);
  delay(1000);
    for(int i = 0; i < 10; i++){
        mySerial.write(137);
  sendHighLow(50);
  sendHighLow(25);
  driveStraight(100);
  driveStraight(0);
  }
  endofCode();

}
void driveStraight(int vel){
  mySerial.write(137);
  sendHighLow(vel);
  mySerial.write(128);
  mySerial.write(1);
}
void drive(int vel, int rad){
  mySerial.write(137);
  sendHighLow(vel);
  sendHighLow(rad);k
}
void sendHighLow(int send) {
  mySerial.write(highByte(send));
  delay(100);
  mySerial.write(lowByte(send));
  delay(100);
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

