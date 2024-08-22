
// library utama
#include <Arduino.h>

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare <component>

// global variable Utama
unsigned int currentTimer = 0, timer = 0, timerinterval = 1000;

// global variable <component>

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void handleCommand(char command)
{
    switch (command)
    {
    case 'A':                        // Jika bt0.val == 1 (bt0 ditekan)
        Serial.println("open tray"); // Debug message
        delay(2000);
        break;
    case 'B':                         // Jika bt0.val == 0 (bt0 dilepas)
        Serial.println("close tray"); // Debug message
        delay(2000);
        break;
    case 'C':                  // Jika bt1.val == 1 (bt1 ditekan)
        Serial.println("run"); // Debug message
        delay(2000);
        break;
    case 'D':                   // Jika bt1.val == 0 (bt1 dilepas)
        Serial.println("show"); // Debug message
        delay(2000);
        break;
    case 'E':                    // Jika bt1.val == 0 (bt1 dilepas)
        Serial.println("print"); // Debug message
        delay(2000);
        break;

    default:
        Serial.println("tidak ada tombol yang ditekan"); // Debug message
        break;
    }
}

// fungsi pendukung
//-----------------------------------------------------------------------------------------------

void monitorSerial()
{
    Serial.println("Hello World");
}
// fungsi utama
//-----------------------------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);
    Serial1.begin(9600);
    Serial.println("Serial communication started."); // Debug message
}

void loop()
{
    if (Serial.available()) // TODO: ganti ke Serial1
    {
        char command = Serial.read(); // TODO: ganti ke Serial1
        Serial.println(command);
        handleCommand(command);
    }
    // function to read along
    currentTimer = millis();
    // fuction to run at interval
    if ((currentTimer - timer) > timerinterval)
    {
        timer = currentTimer;
        monitorSerial();
    }
}
