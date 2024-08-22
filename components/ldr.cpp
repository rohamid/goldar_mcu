
// library utama
#include <Arduino.h>

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare ldr
int ldrA1_pin = A0;
int ldrA2_pin = A1;
int ldrA3_pin = A2;
int ldrA4_pin = A3;
int ldrA5_pin = A4;
int ldrB1_pin = A5;
int ldrB2_pin = A6;
int ldrB3_pin = A7;
int ldrB4_pin = A8;
int ldrB5_pin = A9;
int ldrC1_pin = A10;
int ldrC2_pin = A11;
int ldrC3_pin = A12;
int ldrC4_pin = A13;
int ldrC5_pin = A14;

// global variable Utama
unsigned int timer = 0, timerinterval = 1000;

// global variable ldr
int ldrA1, ldrA2, ldrA3, ldrA4, ldrA5;
int ldrB1, ldrB2, ldrB3, ldrB4, ldrB5;
int ldrC1, ldrC2, ldrC3, ldrC4, ldrC5;

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void readldr()
{
    ldrA1 = analogRead(ldrA1_pin);
    ldrA2 = analogRead(ldrA2_pin);
    ldrA3 = analogRead(ldrA3_pin);
    ldrA4 = analogRead(ldrA4_pin);
    ldrA5 = analogRead(ldrA5_pin);
    ldrB1 = analogRead(ldrB1_pin);
    ldrB2 = analogRead(ldrB2_pin);
    ldrB3 = analogRead(ldrB3_pin);
    ldrB4 = analogRead(ldrB4_pin);
    ldrB5 = analogRead(ldrB5_pin);
    ldrC1 = analogRead(ldrC1_pin);
    ldrC2 = analogRead(ldrC2_pin);
    ldrC3 = analogRead(ldrC3_pin);
    ldrC4 = analogRead(ldrC4_pin);
    ldrC5 = analogRead(ldrC5_pin);
}

// fungsi pendukung
//-----------------------------------------------------------------------------------------------

void monitorSerial()
{
    // Menampilkan nilai ldr Kelompok A
    Serial.print("A: ");
    Serial.print(ldrA1);
    Serial.print("\t");
    Serial.print(ldrA2);
    Serial.print("\t");
    Serial.print(ldrA3);
    Serial.print("\t");
    Serial.print(ldrA4);
    Serial.print("\t");
    Serial.print(ldrA5);
    Serial.println();
    // Serial.print("\t|| ");

    // Menampilkan nilai ldr Kelompok B
    Serial.print("B: ");
    Serial.print(ldrB1);
    Serial.print("\t");
    Serial.print(ldrB2);
    Serial.print("\t");
    Serial.print(ldrB3);
    Serial.print("\t");
    Serial.print(ldrB4);
    Serial.print("\t");
    Serial.print(ldrB5);
    Serial.println();
    // Serial.print("\t|| ");

    // Menampilkan nilai ldr Kelompok C
    Serial.print("C: ");
    Serial.print(ldrC1);
    Serial.print("\t");
    Serial.print(ldrC2);
    Serial.print("\t");
    Serial.print(ldrC3);
    Serial.print("\t");
    Serial.print(ldrC4);
    Serial.print("\t");
    Serial.print(ldrC5);
    Serial.println();

    Serial.println();
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
    readldr();

    // fuction to run at interval
    if ((millis() - timer) > timerinterval)
    {
        timer = millis();
        monitorSerial();
    }
}
