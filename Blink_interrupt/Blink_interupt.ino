//Write the  program timer interrupt based LED blink
//ESP32
//Author:- Amit kumar

int led = 2;//D2 This is a Board LED Pin
int interrupt = 4;//D4 this is a interrupt pin
volatile int state = LOW;//hold the state of LED when toggling

void setup() {
  pinMode(led, OUTPUT);
  /* set the interrupt pin as input pullup*/
  pinMode(interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt), blink, CHANGE);
}

void loop() {
  blink();
}

/* interrupt function toggle the LED */
void blink() {
  state = !state;
  if(!state)
  {
    digitalWrite(led, state);
  }
  else
  {
    
    digitalWrite(led, HIGH); 
  delay(1000);                     
  digitalWrite(led, LOW);    
  delay(1000);
  }
}
