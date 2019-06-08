/*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 16. Apr 2019 *
   * Temp Sensor SE95D *
  ******************************/

//Libraries
#include <avr/io.h>
#include <Wire.h> //for I2C Communicaton

int address = 0x48; // Device address in which is also included the 8th bit for selecting the mode, read in this case.
int temp_register = 2;

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
}

void loop()
{
  Wire.requestFrom(address, temp_register);    // request 2 bytes from slave device

  while(Wire.available())    // slave may send less than requested
  { 
    int MS = Wire.read();    // read LSByte
    int LS = Wire.read();    // read MSByte

    int temp = ((MS <<8) | LS)>>3; // combine the two Bytes
    float temp_f = temp * 0.03125;
    Serial.println(temp_f);         // print the character
  }

  delay(1500); // Wait
}
