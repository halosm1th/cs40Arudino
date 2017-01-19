#include<SoftwareSerial.h>

int rxPin = 10;
int txPin = 11;
int ddPin = 5;

SoftwareSerial mySerial(rxPin, txPin);

void setup() {

  Serial.begin(9600);
  delay(1000);
  Serial.println("Hello Dave");
  // Serial.print("Hello Dave");

  pinMode (ddPin, OUTPUT);
  Serial.println("Hello Dave, pinmod set");
  mySerial.begin(19200);
  Serial.println("Hello Dave, serial began");
  delay(1000);
  Serial.println("Hello Dave, there was a delay");
  if (mySerial.available())
    Serial.println(mySerial.read());
  else
    Serial.println("test"
                  );
  Serial.println("Hello Dave, we read from serial!");
/*
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  */
  delay(2000);
  Serial.println("I'm awake");
  //mySerial.write(128);
  //delay(10);
  Serial.println("Going into safemode");
  mySerial.write(131);
  delay(100);
/*
  Serial.println("Coding the song");
  codeSong();
  Serial.println("Writting the song");
  swrite(141);
  Serial.println("Writing to play");
  swrite(1);
  
  mySerial.write(137);
  sendHighLow(-200);
  sendHighLow(500);

  endofCode();
  /* */
}

void codeSong(){
  Serial.println("Wrote opcode for writing song");
  swrite(140);
  Serial.println("Writing song num");
  swrite(1);
  Serial.println("WRiting song len");
  swrite(16);
  Serial.println("Wriring notes");
  playNote(31,32);
  playNote(33,32);
  playNote(35,32);
  playNote(38,32);
  playNote(40,32);
  playNote(41,32);
  playNote(43,32);
  playNote(47,32);
  playNote(48,32);
  playNote(50,32);
  playNote(52,32);
  playNote(53,32);
  playNote(55,32);
  playNote(57,32);
  playNote(59,32);
  playNote(60,32);
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
  mySerial.write(173);
  delay(100);
}

void sendHighLow(int send) {
  mySerial.write(highByte(send));
  delay(100);
  mySerial.write(lowByte(send));
  delay(100);
}

void loop() {
  // Serial.println("Hello Dave");
}

