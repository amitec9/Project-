#include<Wire.h>
#include<i2cdetect.h>
#define I2C_SDA 2
#define I2C_SCL 4
void setup() {
  Wire.begin(I2C_SDA,I2C_SCL,100000);
  Serial.begin(115200);
  Serial.println("Scanning address range");
  
  

}

void loop() {
  i2cdetect();
  delay(2000);
  // put your main code here, to run repeatedly:

}
