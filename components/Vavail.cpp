
// library utama
#include <Arduino.h>

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare VoltageAvailable
int vavailPin = 26;

// global variable Utama
unsigned int timer = 0, timerinterval = 1000;

// global variable VoltageAvailable
bool vavailStatus = false;

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void vavail()
{
    vavailStatus = digitalRead(vavailPin);
}

// fungsi pendukung
//-----------------------------------------------------------------------------------------------

void monitorSerial()
{
    if (vavailStatus)
    {
        Serial.println("Voltage Available");
    }
    else
    {
        Serial.println("Voltage Not Available");
    }
}
// fungsi utama
//-----------------------------------------------------------------------------------------------
void setup()
{
    Serial.begin(115200);
}

void loop()
{
    // function to read along
    vavail();
    // fuction to run at interval
    if ((millis() - timer) > timerinterval)
    {
        timer = millis();
        monitorSerial();
    }
}
