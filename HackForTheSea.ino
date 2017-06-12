#include <Adafruit_CircuitPlayground.h>
#include <SoftwareSerial.h>

SoftwareSerial ser(0,1);

int pin = 10;
void setup() {
  // put your setup code here, to run once:
  ser.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ser.print(String(CircuitPlayground.temperature()) + ", ");
  //Serial.print(String(CircuitPlayground.temperature()) + ", ");
  ser.print(String(CircuitPlayground.readCap(pin)) + ", ");
  //Serial.print(String(CircuitPlayground.readCap(pin)) + ", ");
  ser.println(String(CircuitPlayground.lightSensor()) + ", ");
  //Serial.println(String(CircuitPlayground.lightSensor()) + ", ");
  delay(1000);
  //Serial.print(String(CircuitPlayground.motionX()) + ", ");
  //Serial.print(String(CircuitPlayground.motionY()) + ", ");
  //Serial.print(String(CircuitPlayground.motionZ()) + ", ");
  
}
