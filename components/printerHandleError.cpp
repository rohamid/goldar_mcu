
// library utama
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Adafruit_Thermal.h"

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare VoltageAvailable
int vavailPin = 26;
// declare printer
#define TX_PIN 9 // Pin untuk TX ke RX printer
#define RX_PIN 8 // Pin untuk RX dari TX printer
// declare indicatorLed
int redLed = 28;
int greenLed = 24;
int blueLed = 22;

// global variable Utama
unsigned int lastTimer = 0, timer = 0, timerinterval = 15000;
byte errorByte = 0;
unsigned int lastTimeerror = 0, timererror = 0, delayblink = 100;

// global variable VoltageAvailable
bool vavailStatus = false;

// global variable printer
SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX
Adafruit_Thermal printer(&mySerial);

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void setError(int errorNumber)
{
    if (errorNumber >= 1 && errorNumber <= 8)
    {
        errorByte |= (1 << (errorNumber - 1));
    }
}

void unsetError(int errorNumber)
{
    if (errorNumber >= 1 && errorNumber <= 8)
    {
        errorByte &= ~(1 << (errorNumber - 1));
    }
}

int hasError()
{
    for (int i = 0; i < 8; i++)
    {
        if (errorByte & (1 << i))
        {
            return i + 1;
        }
    }
    return 0;
}
void vavail()
{
    vavailStatus = digitalRead(vavailPin);
    if (!vavailStatus)
    {
        setError(1);
    }
    else
    {
        unsetError(1);
    }
}

void initPrinter()
{
    mySerial.begin(9600); // Sesuaikan baud rate dengan printer Anda
    printer.begin();      // Memulai printer
}

void init_blink()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);
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

void handleError()
{
    while (errorByte > 0)
    {
        int errorIndicator = hasError();
        lastTimeerror = millis();
        if ((lastTimeerror - timererror) > 2000)
        {
            timererror = lastTimeerror;
            vavail();
            Serial.print("Error pada posisi: ");
            Serial.println(errorIndicator);

            for (int i = 0; i < errorIndicator; i++)
            {
                digitalWrite(redLed, HIGH);
                delay(delayblink);
                digitalWrite(redLed, LOW);
                delay(delayblink);
            }
        }
    }
}

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
    init_blink();

    Serial.println("Get Ready!!");

    vavail();
    handleError();

    Serial.println("All System Ready");
    printer.setSize('M');
    printer.justify('C'); // Menyelaraskan teks ke tengah
    printer.println("ALAT SIAP!");
    printer.feed(2); // Beri jarak 2 baris kosong setelah teks
    Serial.println("ALAT SIAP!");
}

void loop()
{
    // function to read along
    lastTimer = millis();
    handleError();
    vavail();
    // fuction to run at interval
    if ((lastTimer - timer) > timerinterval)
    {
        timer = lastTimer;
        // print("A+");
        monitorSerial();
    }
}
