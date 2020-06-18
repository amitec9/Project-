/*Arduino project
Stepper motor controller rhino rmcs 1101
ESP32
An Arduino ESP32 board
An appropriate USB cable
Prototyping breadboard
2 buttons
2 10K ohm resistors
A stepper motor
Motor drive

Author :- Amit kumar.
*/

uint16_t DISTANCE=3200;
uint8_t StepCounter = 0;
uint8_t Stepping = false;
uint8_t button1=8;//D4 pin
uint8_t button2=9;//D5 pin
uint8_t motorpin1=10;//D18 pin
uint8_t motorpin2=11;//D19 pin


void setup() {
  Serial.println("A stepper motor pin are ready");
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, LOW);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);//speed 115200 port COM7;
  
}

void loop() {

  steppermotor();
   Serial.println("A stepper motor function");
 
}

void steppermotor()
{
   if (digitalRead(button2) == LOW && Stepping == false)
  {
    digitalWrite(motorpin1, LOW);
    Stepping = true;
  }
  if (digitalRead(button1) == LOW && Stepping == false)
  {
    digitalWrite(motorpin1, HIGH);
    Stepping = true;
  }

  if (Stepping == true)
  {
    digitalWrite(motorpin2, HIGH);
    delay(1);
    digitalWrite(motorpin2, LOW);
    delay(1);

    StepCounter = StepCounter + 1;

    if (StepCounter == DISTANCE)
    {
      StepCounter = 0;
      Stepping = false;
    }
  }
 }
