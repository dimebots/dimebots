
#include <Wire.h>
//Click here to get the library: http://librarymanager/All#SparkFun_VCNL4040
#include "SparkFun_VCNL4040_Arduino_Library.h"
VCNL4040 proximitySensor;

void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.swap(1);
  Serial.begin(9600);
  Serial.println("SparkFun VCNL4040 Example");

  Wire.begin(); //Join i2c bus

  if (proximitySensor.begin() == false)
  {
    Serial.println("Device not found. Please check wiring.");
    while (1); //Freeze!
  }
}

void loop()
{
  //Get proximity value. The value ranges from 0 to 65535
  //so we need an unsigned integer or a long.
  unsigned int proxValue = proximitySensor.getProximity(); 

  Serial.print("Proximity Value: ");
  Serial.print(proxValue);
  Serial.println();
  delay(10);

if (proxValue >= 100) {
    digitalWrite(1, HIGH);
    digitalWrite(0, HIGH);
    delay(100);
    digitalWrite(1, LOW);
    digitalWrite(0, LOW);
  } else {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
  }
  
}
