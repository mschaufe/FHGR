/*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 25. FEB 2019 *
   * Poti LED-Stair *
  ******************************/

int potPin = 0; // select the input pin for the potentiometer
int led0 = 12; // the pin the LED is connected to
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;
int val = 0;       // variable to store the value coming from the sensor

void setup() {
    pinMode(led0, OUTPUT); // Declare the LED as an output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor

  if (val==0){
    digitalWrite(led4, LOW);digitalWrite(led3, LOW);digitalWrite(led2, LOW);digitalWrite(led1, LOW);digitalWrite(led0, LOW);
    }else if (val<1*1023/5){
    digitalWrite(led4, HIGH);digitalWrite(led3, LOW);digitalWrite(led2, LOW);digitalWrite(led1, LOW);digitalWrite(led0, LOW);
    }else if (val<2*1023/5){
    digitalWrite(led4, HIGH);digitalWrite(led3, HIGH);digitalWrite(led2, LOW);digitalWrite(led1, LOW);digitalWrite(led0, LOW);
    }else if (val<3*1023/5){
    digitalWrite(led4, HIGH);digitalWrite(led3, HIGH);digitalWrite(led2, HIGH);digitalWrite(led1, LOW);digitalWrite(led0, LOW);
    }else if (val<4*1023/5){
    digitalWrite(led4, HIGH);digitalWrite(led3, HIGH);digitalWrite(led2, HIGH);digitalWrite(led1, HIGH);digitalWrite(led0, LOW);
    }else if (val<5*1023/5){
    digitalWrite(led4, HIGH);digitalWrite(led3, HIGH);digitalWrite(led2, HIGH);digitalWrite(led1, HIGH);digitalWrite(led0, HIGH);
    }
    
}
 
