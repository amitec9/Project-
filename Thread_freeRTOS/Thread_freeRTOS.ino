#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"


TaskHandle_t Task1;



const uint8_t Redpin1=4;


void setup() {
 Serial.begin(115200);
 pinMode(Redpin1,OUTPUT);



 

}
void Task1code( void * pvParameters)
{
  while(1){

    
//        configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
//        Serial.print("Task1 Running on code");
//        digitalWrite(Redpin1,HIGH);
//        delay(1500);
//        digitalWrite(Redpin1,LOW);
//        delay(1500);
    Serial.println("Hello world");
      vTaskDelay(100 / portTICK_RATE_MS);


  }}
  

 void app_main(){
   nvs_flash_init();
//  BaseType_t xReturned;
//  TaskHandle_t xHandle=NULL;
//  xReturned=xTaskCreate(Task1code,"Task1",10000,(void *) 1,0,&xHandle);

//   //*if( xReturned == pdPASS )
//    //{
//        /* The task was created.  Use the task's handle to delete the task. */
//       // vTaskDelete( xHandle );
//  //  }*/
  
  xTaskCreate(&Task1code,"Task1code",2048,NULL,5,NULL);
  }    
  
        
   
  



      

        
        
        
  

void loop() {
  // put your main code here, to run repeatedly:
}
