int incomingByte = 0;   // for incoming serial data
int motor1 = 3;
int motor2=9;
void setup()
{
  Serial.begin(9600);          // opens serial port, sets data rate to 9600 bps
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}
 
void loop()
{ 
  digitalWrite(motor1, LOW);        // turn the motors off by making the voltage LOW
  digitalWrite(motor2, LOW);
 
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();         //received data
  }

  if(incomingByte=='B'||incomingByte==0)
  {
    digitalWrite(motor1, LOW);        // turn the motors off by making the voltage LOW
    digitalWrite(motor2, LOW);
    delay(400);
    incomingByte=0;
  }

  if(incomingByte=='F')            //going straight so both motors spinning
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,HIGH);
    delay(50);
    incomingByte=0;
  }
  if(incomingByte=='R')         //going right
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    delay(50);
    incomingByte=0;
  }

  if(incomingByte=='L')         //going left
  {
    digitalWrite(motor2,HIGH);
    digitalWrite(motor1,LOW);
    delay(50);
    incomingByte=0;
  }
  if(incomingByte=='E')
  {
    delay(50);
    incomingByte=0;
  }
  }

