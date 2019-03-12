  /*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 11. MAR 2019 *
   * Button debounce *
  ******************************/

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
  Serial.begin(9600);

  
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
    int time_start, time_end, time_pressed = 0;
   debouncer.update(); // Update the Bounce instance
   
   if ( debouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
     dispBinary(count++);
     Serial.print("Der Taster ist gedrueckt: ");
     time_start = millis();
     
   }
   debouncer.update(); // Update the Bounce instance
   
   if (debouncer.rose() == 1){
      time_end = millis();
      time_pressed = time_end - time_start;
      Serial.print(time_pressed);Serial.print("\n");
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
