/* number1
nah ini bisaa
*/
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

// library utama
#include <Arduino.h>
int ldrA1_pin = A0;
int ldrA2_pin = A1;
int ldrA3_pin = A2;
int ldrA4_pin = A3;
int ldrA5_pin = A4;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int ldrA1 = analogRead(ldrA1_pin);
    Serial.print("LDR A1: ");
    Serial.println(ldrA1);
    delay(1000);
}
