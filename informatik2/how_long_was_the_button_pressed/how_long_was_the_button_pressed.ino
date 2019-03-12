  /*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 12. MAR 2019 *
   * How long was the button pressed *
  ******************************/
  
#include <Bounce2.h>

#define BUTTON_PIN 13
#define LED_PIN 12

int ledState = LOW;

Bounce debouncer = Bounce(); // Instantiate a Bounce object

void setup() {

  Serial.begin(9600); 
  
  debouncer.attach(BUTTON_PIN,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer.interval(25); // Use a debounce interval of 25 milliseconds
  
  
  pinMode(LED_PIN,OUTPUT); // Setup the LED
  digitalWrite(LED_PIN,ledState);
 
}

void loop() {

   

   debouncer.update(); // Update the Bounce instance

   int time_start, time_end, time_tot;
   
   if ( debouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
     ledState = !ledState; // Toggle LED state
     digitalWrite(LED_PIN,ledState); // Apply new LED state
     time_start = millis();
     Serial.println("Taste ist gedrueckt"); 
   }
   
   if ( debouncer.rose() ) {  // Call code if button transitions from LOW to HIGH
     time_end = millis();
     time_tot=time_end-time_start;
     Serial.print(time_tot); Serial.println("\n"); 
   }
    
}
