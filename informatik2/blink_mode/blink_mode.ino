  /*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 12. MAR 2019 *
   * blink mode *
  ******************************/
  
#include <Bounce2.h>

#define BUTTON_PIN 13
#define LED_PIN 12
 
// Variables will change :
int ledState = LOW;             // ledState used to set the LED

Bounce debouncer = Bounce(); // Instantiate a Bounce object
 
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
 
// constants won't change :
long interval = 500;           // interval at which to blink (milliseconds)
 
void setup() {
  // set the digital pin as output:
  pinMode(LED_PIN, OUTPUT);

  debouncer.attach(BUTTON_PIN,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer.interval(25); // Use a debounce interval of 25 milliseconds

  Serial.begin(9600); 
}
 
void loop() {
  
   debouncer.update(); // Update the Bounce instance

   int time_start, time_end, time_tot = 0;
   
   if ( debouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
     ledState = !ledState; // Toggle LED state
     digitalWrite(LED_PIN,ledState); // Apply new LED state
     time_start = millis();
     Serial.println("Taste ist gedrueckt"); 

     if (time_tot < 500){
      interval = interval/2;
    }
    
   }
   
   if ( debouncer.rose() ) {  // Call code if button transitions from LOW to HIGH
     time_end = millis();
     time_tot=time_end-time_start;
     Serial.print(time_tot); Serial.println("\n"); 
     
     if (time_end <= 1000){
      //code ...
     }
   }

   if (interval < 125){
    interval = 500;
   }
   
 
  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
 
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
 
    // set the LED with the ledState of the variable:
    digitalWrite(LED_PIN, ledState);
  }
}
