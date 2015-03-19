
 
#include <stdio.h>
#include <FastLED.h>
 
//#define NUM_LEDS      60
//#define DATA_PIN       5
#define NUM_STRIPS 1
#define NUM_LEDS_PER_STRIP 60
#define LED_TYPE    TM1809
#define COLOR_ORDER RBG
//#define BASS_PIN      A0
//#define MID_PIN       A1
//#define TREBLE_PIN    A2
 const int buttonPin1 = 2;
 const int buttonPin2 = 13;
 const int buttonPin3 = 10;
 
//create an array of RGB values for the number of leds on the strip.
//CRGB leds[NUM_LEDS];
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

void setup()
{
  pinMode(buttonPin1, INPUT);     
  pinMode(buttonPin2, INPUT);     
  pinMode(buttonPin3, INPUT);     

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, 10, COLOR_ORDER>(leds[0], NUM_LEDS_PER_STRIP);
  Serial.begin(9600);
  //Specify the led strip type and the data pin used to send data to the led strip
  
      

  //Initially turn all leds off
  for(int i = 0; i < sizeof(CRGB); i++)
  {
     leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}
 
void loop()
{
if (buttonPin1 == HIGH) { 
  // read the bass, mid and treble values. These values will be between 0-1023.
 //while (Serial.available()) {
  int bass =Serial.parseInt();// random(0, 1023);//
//  Serial.print("bass= ");
//  Serial.println(bass);
 // int mid = analogRead(MID_PIN);
 // int treble = analogRead(TREBLE_PIN);
 
  //calculate the number of LEDs to be lit using the bass value
  int litLEDCount = map(bass, 0, 1023, 0, NUM_LEDS);
// Serial.print("LEDCount= ");
// Serial.println(litLEDCount);
  //map the bass, mid and treble values to red, green and blue values. The rgb values can only be from 0-255
  byte rVal = map(bass, 0, 1023, 0, 255);
  byte gVal = map(bass, 0, 1023, 0, 255);
  byte bVal = map(bass, 0, 1023, 0, 255);
 
  //turn off all the LEDs on the array
  FastLED.clear();
  //update the LED strip with calculated red, green and blue values
  for(int i = 0; i < litLEDCount; i++)
  {
    leds[i] = CRGB(bVal,rVal,gVal);//CHSV((bass*2 % 255), 255, (bass*2)% 255);//
    
  }
  //display the LEDs
  FastLED.show();
 
  delay(50);
 }
 
 ////////////////////////////////////////////////////
 
 if (buttonPin2 == HIGH) { 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(100);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
   }
 }
 
 ///////////////////////////////////////////////////////////////
 
 if (buttonPin2 == HIGH) { 
   
 }
 
}
