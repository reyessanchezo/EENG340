/*
  ESP32 attached parasitically to a Zumo bot. Power, I2C Data and Clock from Zumo bot to ESP32.

  Steps:
  1. Connect to the access point "ESParasite", password "HungryESP"
  2. Point your web browser to http://192.168.4.1/OFF to open the interface
  3. Follow links to do things!
  4. Keep an eye on the Zumo, make sure it doesn't fall off a cliff

*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

//#define LED_BUILTIN 2   // Set the GPIO pin where you connected your test LED or comment this line out if your dev board has a built-in LED

// Set these to your desired credentials, thanks Paul for the idea!
const char *ssid = "ESParasite";
const char *password = "HungryESP";

WiFiServer server(80);

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


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  // a valid password must have more than 7 characters
  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while (1);
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");

  Wire.setPins(13, 14); // pick whichever pins you like. //setPins(data,clock)
  Wire.begin();

  Wire.beginTransmission(0x21); //roll calling for the Slave
  byte busStatus = Wire.endTransmission();
  if (busStatus != 0x00)
  {
    while (busStatus != 0x00) {
      Wire.beginTransmission(0x21); //roll calling for the Slave
      busStatus = Wire.endTransmission();
      delay(1000);
      Serial.println("I2C Bus communication problem...! Trying again.");
    }
  }

}

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/ON\">here</a> to turn ON the LED.<br>");
            client.print("Click <a href=\"/OFF\">here</a> to turn OFF the LED.<br>");
            client.print("Click <a href=\"/Forward\">here</a> to scoot forward.<br>");
            client.print("Click <a href=\"/Reverse\">here</a> to scoot reverse.<br>");
            client.print("Click <a href=\"/Left\">here</a> to scoot left.<br>");
            client.print("Click <a href=\"/Right\">here</a> to scoot right.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /ON")) {
          digitalWrite(LED_BUILTIN, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /OFF")) {
          digitalWrite(LED_BUILTIN, LOW);                // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /Forward")) {
          SendToZumo(1, 1.0);                            // Forward 1 inch
        }
        if (currentLine.endsWith("GET /Reverse")) {
          SendToZumo(2, 1.0);                            // Reverse 1 inch
        }
        if (currentLine.endsWith("GET /Right")) {
          SendToZumo(3, 90.0);                            // Right 90 degrees
        }
        if (currentLine.endsWith("GET /Left")) {
          SendToZumo(4, 90.0);                            // Left 90 degrees
        }
        Serial.println(currentLine);
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
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
    Can send 1 through 4 for cmd, corresponding to forward, reverse, right, and left
    Argument is converted to two 2-byte values which are sent to the Zumo bot and decoded as a float
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
