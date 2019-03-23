/*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 19. MAR 2019 *
   * TIMER *
  ******************************/
  
unsigned long uhr = 0;

void setup() {
  // put your setup code here, to run once:

  Timer_one_16_init(); // configure the timer 

  Serial.begin(115200);

   Serial.print("TCCR1A: "); Serial.println(TCCR1A, BIN);
   Serial.print("TCCR1B: "); Serial.println(TCCR1B, BIN);
   Serial.print("TCCR1C: "); Serial.println(TCCR1C), BIN;
   Serial.print("TCNT1H: "); Serial.println(TCNT1H), BIN;
   Serial.print("TCNT1L: "); Serial.println(TCNT1L, BIN);
   Serial.print("OCR1AH: "); Serial.println(OCR1AH, BIN);
   Serial.print("OCR1AL: "); Serial.println(OCR1AL, BIN);
   Serial.print("OCR1BH: "); Serial.println(OCR1BH, BIN);
   Serial.print("OCR1BL: "); Serial.println(OCR1BL, BIN);
   Serial.print("ICR1H: "); Serial.println(ICR1H, BIN);
   Serial.print("ICR1L: "); Serial.println(ICR1L, BIN);
   Serial.print("TIMSK1: "); Serial.println(TIMSK1, BIN);
   Serial.print("TIFR1: "); Serial.println(TIFR1, BIN);

}

void loop() {
  
 Serial.println(uhr);

}

void Timer_one_16_init(){

// TCCR
     // CPU Freq 16Mhz
     // Need interval of 1Ms ==> 0,001/(1/16000000) = 16000 ticks
     //
     // Prescaler 64 ==> resolution changes from 0,0000000625 to 0,000004
     // Need interval of 1Ms ==> 0,001/((1/16000000)*64) = 250 ticks
     
     
     // Set prescaler to 0 ; (1 << CS10)
     // Clear Timer on Compare (CTC) mode ; (1 << WGM12)
     TCCR1A = 0 ;    
     TCCR1B |= (1 << WGM12)|(1 << CS10) ;
     

     // set Output Compare Register to (250 - 1) ticks
     OCR1A = 124;
     
     // TCNT1
     // Timer count = (required delay/clock time period) - 1
     // 249 = (0,001/0,000004) - 1
     
     // initialize counter
     TCNT1 = 0 ;
     
     // TIMSK1
     // Set Timer Interrupt Mask Register to 
     // Clear Timer on Compare channel A for timer 1
     TIMSK1 |= (1 << OCIE1A) ;

}

ISR(TIMER1_COMPA_vect) {
  uhr++;
}
