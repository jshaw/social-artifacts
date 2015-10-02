/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include "pitches.h"

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A1;
const int analogInPin3 = A2;

const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int analogOutPin2 = 10; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int sensorValue3 = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int outputValue2 = 0;        // value output to the PWM (analog out)

int rdm = 0;
int mapped_input = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);

  sensorValue3  = analogRead(analogInPin3);

  Serial.print("sensorValue3: ");
  Serial.println(sensorValue3);
//  sensorValue2 = analogRead(analogInPin2);
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);
//  outputValue = map(sensorValue2, 0, 1023, 0, 255);
  outputValue = sensorValue;
//  outputValue = map(sensorValue2, 0, 1023, 0, 255);
  // change the analog out value:
//  analogWrite(analogOutPin, outputValue);
//  analogWrite(analogOutPin2, outputValue2);

//  rdm = random(0, 30);
  mapped_input= map(sensorValue3, 0, 1023, 1, 15);

  Serial.print("\n mapped_input");
  Serial.print(mapped_input);

//  tone(9, outputValue, 100);
  if (sensorValue > 0){
    if(mapped_input > 1){
      tone(9, sensorValue3 * mapped_input, 100);
    }
    
  }

  // print the results to the serial monitor:
  Serial.print("\n sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t sensor2 = " );
  Serial.print(sensorValue2);
//  Serial.print("\t output = ");
//  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
//  delay(1000);
//  delay(1);
}
