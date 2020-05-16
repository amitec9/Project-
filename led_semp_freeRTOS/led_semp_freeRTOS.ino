
TaskHandle_t Task1;
TaskHandle_t Task2;
SemaphoreHandle_t semaphore;


const uint8_t Redpin1=4;
const uint8_t Redpin2=5;


void setup() {
 Serial.begin(115200);
 pinMode(Redpin1,OUTPUT);
 pinMode(Redpin2,OUTPUT);
 semaphore = xSemaphoreCreateMutex();
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

 

}
void Task1code( void * pvParameters)
{
  while(1){

    
  
        Serial.print("Task1 Running on code");
        Serial.println(xPortGetCoreID());
        xSemaphoreTake(semaphore, portMAX_DELAY);
        digitalWrite(Redpin1,HIGH);
        delay(1500);
        digitalWrite(Redpin1,LOW);
        delay(1500);
         xSemaphoreGive(semaphore);
    delay(50);
    
        
    }
    
    
  }
  


        void Task2code( void * pvParameters)
      {
        while(1){
          
        
          
          Serial.print("Task2 Running on code");
          Serial.println(xPortGetCoreID());
          xSemaphoreTake(semaphore, portMAX_DELAY);
      digitalWrite(Redpin2,HIGH);
      delay(700);
      digitalWrite(Redpin2,LOW);
      delay(700);
       xSemaphoreGive(semaphore);
    delay(50);
    
        
         
        }
        }

      

        
        
        
  

void loop() {
  // put your main code here, to run repeatedly:
}
