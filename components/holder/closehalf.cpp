/*
start -> [init] -> open -> close -> run
*/
// library utama
#include <Arduino.h>
#include <StepperMotor.h>

// Global variable and declaration
//-----------------------------------------------------------------------------------------------
// declare indicatorLed
int redLed = 28;
int greenLed = 24;
int blueLed = 22;

// declare VoltageAvailable
int vavailPin = 26;

// declare Stepper
#define STEPPER_PIN_1 2
#define STEPPER_PIN_2 3
#define STEPPER_PIN_3 4
#define STEPPER_PIN_4 5
#define STEPPER_LIMIT_PIN 23
StepperMotor motor(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);

// global variable Utama
bool startStatus = false;
unsigned int currentTimer = 0, timer = 0, timerinterval = 1000;
byte errorByte = 0;

// global variable indicatorLed
int delayblink = 100;

// global variable VoltageAvailable
bool vavailStatus = false;

// global variable Stepper
bool closeFull = false, openFull = false;

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

void init_blink()
{
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);
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

void checkTrayCLose()
{
    closeFull = digitalRead(STEPPER_LIMIT_PIN);
}

void motorMove(int command)
{
    switch (command)
    {
    case 0:

        if (openFull)
        {
            Serial.println("Close Tray Half");
            motor.stepMotor(720, false); // TODO: HARUSNYA 720
            openFull = false;
        }
        else
        {
            Serial.println("Close Tray Full");
            while (!closeFull)
            {
                checkTrayCLose();
                motor.stepMotor(10, false);
            }
        }
        break;

    case 1:
        if (closeFull)
        {
            Serial.println("Open Tray Full");
            motor.stepMotor(1200, true); // TODO: HARUSNYA 12000
            openFull = true;
        }
        break;

    default:
        break;
    }
}
// fungsi pendukung
//-----------------------------------------------------------------------------------------------
void blinkNotification(int led, int times)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(led, HIGH);
        delay(delayblink);
        digitalWrite(led, LOW);
        delay(delayblink);
    }
}

void handleCommand(char command)
{
    switch (command)
    {
    case '1':                           // Jika bt0.val == 1 (bt0 ditekan)
        Serial.println("Start button"); // Debug message
        startStatus = true;
        blinkNotification(greenLed, 1);

        break;

    case 'A':                          // Jika bt0.val == 1 (bt0 ditekan)
        Serial.println("open button"); // Debug message
        motorMove(1);                  // open tray full
        blinkNotification(greenLed, 2);
        break;

    case 'B':                           // Jika bt0.val == 0 (bt0 dilepas)
        Serial.println("close button"); // Debug message
        motorMove(0);                   // close tray full
        blinkNotification(greenLed, 2);
        break;

    case 'C':                         // Jika bt1.val == 1 (bt1 ditekan)
        Serial.println("run button"); // Debug message
        delay(2000);
        break;
    case 'D':                          // Jika bt1.val == 0 (bt1 dilepas)
        Serial.println("show button"); // Debug message
        delay(2000);
        break;
    case 'E':                           // Jika bt1.val == 0 (bt1 dilepas)
        Serial.println("print button"); // Debug message
        delay(2000);
        break;

    default:
        Serial.println("tidak ada tombol yang ditekan"); // Debug message
        break;
    }
}

void getReady()
{
    Serial.println("Get Ready!!");

    digitalWrite(redLed, HIGH);
    delay(delayblink);
    digitalWrite(redLed, LOW);
    delay(delayblink);
    digitalWrite(greenLed, HIGH);
    delay(delayblink);
    digitalWrite(greenLed, LOW);
    delay(delayblink);
    digitalWrite(blueLed, HIGH);
    delay(delayblink);
    digitalWrite(blueLed, LOW);
    delay(delayblink);
}

void handleError()
{
    while (errorByte > 0)
    {
        int errorIndicator = hasError();
        currentTimer = millis();
        if ((currentTimer - timer) > 2000)
        {
            timer = currentTimer;
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
    Serial.println("Running");
}
// fungsi utama
//-----------------------------------------------------------------------------------------------
void setup()
{
    // serial
    Serial.begin(115200);
    Serial1.begin(9600);

    // init component
    init_blink();

    // run once
    getReady();
    motorMove(0);
    vavail();
    handleError();

    // tell the world device ready
    Serial.println("All System Ready");

    Serial.println("Serial communication started."); // Debug message
}

void loop()
{
    // check serial
    if (Serial.available()) // TODO: ganti ke Serial1
    {
        char command = Serial.read(); // TODO: ganti ke Serial1
        Serial.println(command);
        handleCommand(command);
    }

    // function to read along
    handleError();
    vavail();
    checkTrayCLose();
    currentTimer = millis();

    // fuction to run at interval
    if ((currentTimer - timer) > timerinterval)
    {
        timer = currentTimer;
        if (startStatus)
        {
            monitorSerial();
        }
        else
        {
            Serial.println("Device not started yet.");
        }
    }
}
