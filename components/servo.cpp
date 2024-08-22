
// library utama
#include <Arduino.h>
#include <Servo.h>

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare Servo
int servoStirPin = 6;     // Pin Arduino yang terhubung ke pin sinyal servo pertama
int servoMountingPin = 7; // Pin Arduino yang terhubung ke pin sinyal servo kedua

// global variable Utama
unsigned int currentTimer = 0, timer = 0, timerinterval = 1000;
unsigned int currentTimerServo = 0, timerServo = 0, timerIntervalServo = 20;

// global variable Servo
Servo servoStir;     // Membuat objek untuk servo pertama
Servo servoMounting; // Membuat objek untuk servo kedua
bool stirring = false, stirringCW = true;
int servoStirPos = 0;

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void initServo()
{
    servoStir.attach(servoStirPin);         // Menghubungkan objek servo pertama dengan pin servo
    servoMounting.attach(servoMountingPin); // Menghubungkan objek servo kedua dengan pin servo
}
void stirServo()
{
    currentTimerServo = millis();
    if (stirring && (currentTimerServo - timerServo) > timerIntervalServo)
    {
        timerServo = currentTimerServo;
        if (stirringCW)
        {
            servoStirPos += 5;
            if (servoStirPos >= 180)
            {
                stirringCW = false;
            }
        }
        else
        {
            servoStirPos -= 5;
            if (servoStirPos <= 0)
            {
                stirringCW = true;
            }
        }
        servoStir.write(servoStirPos);
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
    Serial.begin(115200);
    initServo();

    servoStir.write(80);      // Putar servo pertama ke posisi 0 derajat
    servoMounting.write(180); // Putar servo pertama ke posisi 90 derajat
    delay(2000);

    servoMounting.write(80); // Putar servo pertama ke posisi 90 derajat
    stirring = true;
}

void loop()
{
    // function to read along
    currentTimer = millis();
    stirServo();
    // fuction to run at interval
    // if ((currentTimer - timer) > timerinterval)
    // {
    //   timer = millis();
    //   monitorSerial();
    // }
    if ((currentTimer - timer) > 10000)
    {
        timer = millis();
        stirring = false;
        servoMounting.write(180); // Putar servo pertama ke posisi 90 derajat
        monitorSerial();
    }
}
