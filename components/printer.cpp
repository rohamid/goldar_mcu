
// library utama
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Adafruit_Thermal.h"

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare <component>

// global variable Utama
unsigned int timer = 0, timerinterval = 10000;

// global variable printer
#define TX_PIN 9                         // Pin untuk TX ke RX printer
#define RX_PIN 8                         // Pin untuk RX dari TX printer
SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX
Adafruit_Thermal printer(&mySerial);

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void initPrinter()
{
    mySerial.begin(9600); // Sesuaikan baud rate dengan printer Anda
    printer.begin();      // Memulai printer
}

void print(String bloodType)
{

    delay(2000);

    printer.setSize('M');
    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.println("KARTU TEST");
    printer.println("GOLONGAN DARAH");

    printer.feed(2); // Beri jarak 2 baris kosong setelah teks

    printer.justify('M'); // Kembali ke penyelarasan kiri
    printer.println("NAMA :");
    printer.println("UMUR :");

    printer.feed(2); // Beri jarak 2 baris kosong setelah teks

    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.setSize('S');
    printer.println("HASIL");
    printer.setSize('L');
    printer.println(bloodType);

    printer.feed(3); // Beri jarak 2 baris kosong setelah teks
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
    Serial.begin(115200);
    initPrinter();

    printer.setSize('M');
    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.println("ALAT SIAP!");
    printer.feed(2); // Beri jarak 2 baris kosong setelah teks
    Serial.println("ALAT SIAP!");
    delay(5000);
}

void loop()
{
    // function to read along

    // fuction to run at interval
    if ((millis() - timer) > timerinterval)
    {
        timer = millis();
        print("A+");
        monitorSerial();
    }
}
