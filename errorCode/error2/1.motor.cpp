
/*
cannot turn the motor
*/
// library utama
#include <Arduino.h>
#include <Stepper.h>
// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare stepper
const int stepsPerRevolution = 2048; // Biasanya 2048 untuk 28BYJ-48
Stepper myStepper(stepsPerRevolution, 5, 4, 3, 2);

// Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

// global variable Utama
unsigned int currentTimer = 0, timer = 0, timerinterval = 1000;

// global variable stepper
int motorSpeed = 60;

// fungsi dari komponen
//-----------------------------------------------------------------------------------------------

void initStepper()
{
    myStepper.setSpeed(motorSpeed);
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
    // initStepper();
    myStepper.setSpeed(20);

    // long stepsIn10Seconds = motorSpeed * stepsPerRevolution / 60 * 10;
    // long stepsIn10Seconds = motorSpeed * stepsPerRevolution;

    // myStepper.step(stepsIn10Seconds);
    myStepper.step(-4000);
    myStepper.step(stepsPerRevolution);

    delay(2000);
}

void loop()
{
    // myStepper.step(stepsPerRevolution);
    // // function to read along
    // currentTimer = millis();
    // // fuction to run at interval
    // if ((currentTimer - timer) > timerinterval)
    // {
    //   timer = currentTimer;
    //   monitorSerial();
    // }
}
