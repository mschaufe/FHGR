#include <Bounce2.h> // https://www.arduinolibraries.info/libraries/bounce2


// The pins to which we've wired each of the LEDs
int ledPins[] = {8, 9, 10, 11, 12};

// The button
int buttonPin = 13;

// The number we're going to display.
byte count;

Bounce debouncer = Bounce(); // Instantiate a Bounce object

/*
 * Set each pin to be used as output, and default to zero.
 */
void setup(void)
{
  debouncer.attach(buttonPin,INPUT_PULLUP);
  debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  
  for (byte i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  count = 0;
  
}

/*
 *  Constantly increase, display, and delay.
 */
void loop(void){
   debouncer.update(); // Update the Bounce instance
   if ( debouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
     dispBinary(count++);
   }

  
}

/*
 *  Show a single number.
 */
void dispBinary(byte n)
{
  for (byte i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], n & 1);
    n /= 2;
  }
}
