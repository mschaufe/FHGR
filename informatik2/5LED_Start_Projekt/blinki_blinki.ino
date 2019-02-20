/*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 20. FEB 2019 *
   * 5 LED Start-Projekt *
  ******************************/

int led0 = 12; // the pin the LED is connected to
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;

void setup() {
    pinMode(led0, OUTPUT); // Declare the LED as an output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop() {
    for(int i=8; i<13; i++) {
        digitalWrite(i, HIGH); // Turn the LED on
        delay(40); // Wait for 200 milliseconds (1 second)
    }
    for(int i=12; i>7; i--) {
        digitalWrite(i, LOW); // Turn the LED off
        delay(200);
    }
    delay(400);
}