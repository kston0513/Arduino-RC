#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);

int velL = 255; // output level of left wheel speed, from 0 to 255
int velR = 255; // output level of right wheel speed, from 0 to 255
int LA = 2; // LeftA
int LB = 3; // LeftB
int RA = 4; // RightA
int RB = 5; // RightB
int enableLPin = 10; 
int enableRPin = 11;
char out = OUTPUT;

char in;

  void setup() {
    BTSerial.begin(9600);
    Serial.begin(9600);
    pinMode(LA, out);
    pinMode(LB, out);
    pinMode(enableLPin, out);
    pinMode(RA, out);
    pinMode(RB, out);
    pinMode(enableRPin, out);
    analogWrite(enableLPin, velL); // speed of Left motor.
    analogWrite(enableRPin, velR); // speed of Right motor.
  }

void loop() {
  if (BTSerial.available())
  {
    in =BTSerial.read();
      Serial.write(in);
  }
  if (Serial.available())
    {
      BTSerial.write(Serial.read());

  Serial.print("data=");
  Serial.println(in); 
    }
  switch(in){
    case 'F':Forward(); break;
    case 'R':Right(); break;
    case 'S':Stop(); break;
    case 'L':Left(); break;
    case 'B':Back(); break;
  }
    }
void Forward(){
  digitalWrite(LA,LOW);
  digitalWrite(LB,HIGH);
  digitalWrite(RA,LOW);
  digitalWrite(RB,HIGH);
}
void Right()//Right turn
  {
  digitalWrite(LA,LOW);
  digitalWrite(LB,HIGH);
  digitalWrite(RA,LOW);
  digitalWrite(RB,LOW);
}
void Left()//Left turn
  {
  digitalWrite(LA,LOW);
  digitalWrite(LB,LOW);
  digitalWrite(RA,LOW);
  digitalWrite(RB,HIGH);
}
void Back()
  {
  digitalWrite(LA,HIGH);
  digitalWrite(LB,LOW);
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
}
void Stop(){
  digitalWrite(LA,LOW);
  digitalWrite(LB,LOW);
  digitalWrite(RA,LOW);
  digitalWrite(RB,LOW);
}
