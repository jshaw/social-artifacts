/*

  Social Artifacts

  Original code referenced from the Analog input, analog output, serial output example

  DOCS
  Reads the analog output from a Digibird and interperits it 
  and minipulates it using a Poteniometer and digitizes it 
  and outputs the digital audio based on the original Digibird audio frequency
  to a larger speaker.
  
  By: Jordan Shaw 

 */

// Used this file as a reference
// in the beginning of the project
//#include "pitches.h"

// These constants won't change.  They're used to give names
// to the pins used:
const int analogAudioIn = A0;  // Analog input pin that the potentiometer is attached to
const int analogPotentiometer= A2;

// Analog output pin to send digital reinterpertation of the bird song
const int analogOutPin = 9; 

// value read from the bird
int analogAudioValue = 0;        
int analogPotentiometerValue = 0;
int mapped_input = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  analogAudioValue  = analogRead(analogAudioIn);

  Serial.print("\n analogAudioValue : ");
  Serial.println(analogAudioValue);
  
  // read potentiometer analog input
  analogPotentiometerValue  = analogRead(analogPotentiometer);

  // Map the Potentiometer value to a number that can be multiplied and 
  // added to the frequency for the digital output
  // bird song input to a resonable value
  mapped_input= map(analogPotentiometerValue, 0, 1023, 0, 100);

  Serial.print("\n mapped_input: ");
  Serial.print(mapped_input);

  // to accound for some weird readings and make sure there's no sound
  // when there shouldn't be I put these checks into place
  if (analogAudioValue  > 6){
    if(mapped_input > 1){
      tone(analogOutPin, analogAudioValue * mapped_input, 100);
    } 
  }
}
