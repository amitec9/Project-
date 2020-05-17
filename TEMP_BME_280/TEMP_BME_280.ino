#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define I2C_SDA 21
#define I2C_SCL 22
#define I2C_ADDRESS 0x76

TwoWire I2CBMC = TwoWire(0);

//Adafruit_BME280 bme;
Adafruit_BMP280 bmp;
uint32_t delayTime;

void setup(){
  Serial.begin(115200);
  
  Serial.println(F("BME 280 test"));
  I2CBMC.begin(I2C_SDA,I2C_SCL,100000);

  bool status;

  status = bmp.begin(0x76);
  if(!status){
    Serial.println("Fail check wiring");
    while(1);
    }
    Serial.println("Default test");
    delayTime=1000;
    Serial.println();

    /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  
  }

  void loop() { 
    
  printValues();
  delay(delayTime);
}

void printValues() {
        
  
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
}
  
