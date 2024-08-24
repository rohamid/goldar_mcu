
// library utama
#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare sound
SoftwareSerial mySoftwareSerial(11, 10); // RX, TX

// global variable Utama
unsigned int timer = 0, timerinterval = 5000;

// global variable sound
DFRobotDFPlayerMini myDFPlayer;

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void initSound()
{
    mySoftwareSerial.begin(9600);

    if (!myDFPlayer.begin(mySoftwareSerial))
    { // Use softwareSerial to communicate with mp3.
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while (true)
            ;
    }
    Serial.println(F("DFPlayer Mini online."));
    myDFPlayer.play(8); // a+

    myDFPlayer.volume(30); // Set volume value. From 0 to 30
}

void sound(int numberMusic)
{

    myDFPlayer.play(numberMusic); // a+
    delay(2000);
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
    delay(3000);
    initSound();
}

void loop()
{
    // function to read along

    // fuction to run at interval
    if ((millis() - timer) > timerinterval)
    {
        timer = millis();
        sound(1);
        // sound(2);
        // sound(3);
        // sound(4);
        // sound(5);
        // sound(6);
        // sound(7);
        // sound(8);
        monitorSerial();
    }
}
