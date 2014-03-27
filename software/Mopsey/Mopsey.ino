#include <Adafruit_NeoPixel.h>
#include <Servo.h> 

int EYE_PIN = 8;  // Connect the NeoPixel signal to this pin.
int RGHT_ARM = 9;  // Connect the right arm servo signal to this pin.
int LEFT_ARM = 10;  // Connect the left arm servo signal to this pin.

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, EYE_PIN, NEO_GRB + NEO_KHZ800);

Servo rghtServo;
Servo leftServo;
int pos = 0; 

void setup() 
{
  // Initialize eye pixel to 'off'
  strip.begin();
  strip.show();

  // Attach servos to the specified pins
  rghtServo.attach(RGHT_ARM);
  leftServo.attach(LEFT_ARM);
} 


void loop() 
{
  // Set the color of the eye pixel to blue
  strip.setPixelColor(0, strip.Color(155, 0, 155));
  strip.show();

  // Swap the arms back-and-forth 
  for(pos = 0; pos < 180; pos += 1)
  {                     
    rghtServo.write(pos);     
    leftServo.write(pos);      
    delay(15);                
  } 
  for(pos = 180; pos>=1; pos-=1)
  {                     
    rghtServo.write(pos);     
    leftServo.write(pos);       
    delay(15);                 
  } 

  delay(150);
}
