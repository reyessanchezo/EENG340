#include<Wire.h>

byte command = 0;
int decimal = 0;
int value = 0;

#define FORWARD 1
#define REVERSE 2
#define RIGHT 3
#define LEFT 4

void SendToZumo(byte cmd, double argument);
void updateI2C();

void setup()
{
  Serial.begin(9600);
  Wire.setPins(13, 14); // pick whichever pins you like. //setPins(data,clock)
  Wire.begin();

  Wire.beginTransmission(0x21); //roll calling for the Slave
  byte busStatus = Wire.endTransmission();
  if (busStatus != 0x00)
  {
    Serial.print("I2C Bus communication problem...!");
    while (1);  //wait for ever
  }
  Serial.println("Target found! Enter command: ");
}

void loop()
{

  
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int separatorIndex = input.indexOf(',');
    byte cmd = input.substring(0, separatorIndex).toInt();
    double argument = input.substring(separatorIndex + 1).toDouble();

    // Call your function with the parsed arguments
    SendToZumo(cmd, argument);
  }
  
  /* Testing by cycling through commands
    command++;
    if(command > 5){
    command = 0;
    }
    value = 5;
    decimal+= 50;
    if(decimal > 255){
    decimal = 0;
    }
  */

  /* Another test: Sending one of each command forever. */
  /*
    command++;
    if(command > 4){
    command = 1;
    }
    switch (command){
    case 1: // Forward
      value = 3;
      decimal = 0;
      break;
    case 2: // Reverse
      value = 3;
      decimal = 0;
      break;
    case 3: // Right
      value = 360;
      decimal = 0;
      break;
    case 4: // Left
      value = 360;
      decimal = 0;
      break;

    }


    //If I want to do p.left(90.5)
    //left becomes command 4, 90 becomes value=90, decimal = 5*256
  */

  //-------------------
  delay(500);        //test interval
}

void updateI2C() {
  Wire.beginTransmission(0x21); //address byte in write mode=0100001+0=01000010= 0x42 (queued)

  // transmit data byte by byte
  // format: command, arg(byte1, byte2, byte3) ...
  // arg() is combined on the zumo-side to be a float with [byte1<<8] | [byte2] as the integer part and byte3 as the decimal,
  // commands are 1,2,3,4 corresponding to forward(float inches), reverse(float inches), right(float degrees), left(float degrees)
  Wire.write(command);
  Wire.write(highByte(value));
  Wire.write(lowByte(value));
  Wire.write(highByte(decimal));
  Wire.write(lowByte(decimal));

  Wire.endTransmission();   //all queued data bytes are sent on ACK
  Serial.println("Sent!");
}

void SendToZumo(byte cmd, double argument) {
  /*
  * Can send 1 through 4 for cmd, corresponding to forward, reverse, right, and left
  * Argument is converted to two 2-byte values which are sent to the Zumo bot and decoded as a float
  */
  command = cmd;
  value = (int)argument;
  decimal = argument - value;

  switch (cmd) {
    case 1: // Forward
      if (value > 120) { //Arbitrary 10 foot limit
        value = 120;
      }
      break;
    case 2: // Reverse
      if (value > 120) { //Arbitrary 3 foot limit
        value = 120;
      }
      break;
    case 3: // Right
      if (value > 1800) { //Arbitrary 5 rotation limit
        value = 1800;
      }
      break;
    case 4: // Left
      if (value > 1800) { //Arbitrary 5 rotation limit
        value = 1800;
      }
      break;
    default: // all others
      value = 0;
      decimal = 0;
      break;
  } // end switch statement
  Serial.print("Sending ");
  Serial.print(cmd);
  Serial.print(", ");
  Serial.print(argument);
  Serial.println("...");
  updateI2C(); 
}
