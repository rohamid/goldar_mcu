/* resolve
    Serial.print(ldrA1 + "\t");
    jadi error karena tidak bisa menambahkan integer dengan string
*/
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

// library utama
#include <Arduino.h>

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
    Serial.print("Kelompok A: ");
    Serial.print(ldrA1 + "\t");
    Serial.print(ldrA2 + "\t");
    Serial.print(ldrA3 + "\t");
    Serial.print(ldrA4 + "\t");
    Serial.println(ldrA5);

    // Menampilkan nilai ldr Kelompok B
    Serial.print("Kelompok B: ");
    Serial.print(ldrB1 + "\t");
    Serial.print(ldrB2 + "\t");
    Serial.print(ldrB3 + "\t");
    Serial.print(ldrB4 + "\t");
    Serial.println(ldrB5);

    // Menampilkan nilai ldr Kelompok C
    Serial.print("Kelompok C: ");
    Serial.print(ldrC1 + "\t");
    Serial.print(ldrC2 + "\t");
    Serial.print(ldrC3 + "\t");
    Serial.print(ldrC4 + "\t");
    Serial.println(ldrC5);

    Serial.println();
}
// fungsi utama
//-----------------------------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);
    delay(1000);
}

void loop()
{

    readldr();
    monitorSerial();
    Serial.println("Hello World");
    delay(1000);
}
