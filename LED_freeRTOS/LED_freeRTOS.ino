
TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;

const uint8_t Redpin1=4;
const uint8_t Redpin2=5;
const uint8_t Redpin3=2;

void setup() {
 Serial.begin(115200);
 pinMode(Redpin1,OUTPUT);
 pinMode(Redpin2,OUTPUT);
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  

delay(500);
 xTaskCreatePinnedToCore(Task2code,"Task2",10000,NULL,2,&Task2,1);
 delay(500);
 xTaskCreatePinnedToCore(Task3code,"Task3",10000,NULL,3,&Task3,1);
 delay(500);
 

}
void Task1code( void * pvParameters)
{
  while(1){
    Serial.print("Task1 Running on code");
    Serial.println(xPortGetCoreID());
digitalWrite(Redpin1,HIGH);
delay(500);
digitalWrite(Redpin1,LOW);
delay(500);
    
    
  }
  }


        void Task2code( void * pvParameters)
      {
        while(1){
          Serial.print("Task2 Running on code");
          Serial.println(xPortGetCoreID());
      digitalWrite(Redpin2,HIGH);
      delay(1000);
      digitalWrite(Redpin2,LOW);
      delay(1000);
          
          
        }
        }

        void Task3code( void * pvParameters)
      {
        while(1){
          Serial.print("Task3 Running on code");
          Serial.println(xPortGetCoreID());
      digitalWrite(Redpin3,HIGH);
      delay(1500);
      digitalWrite(Redpin3,LOW);
      delay(1500);
          
          
        }
        }

        
        
        
  

void loop() {
  // put your main code here, to run repeatedly:

}
