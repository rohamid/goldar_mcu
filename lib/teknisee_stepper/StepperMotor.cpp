#include "StepperMotor.h"

// Konstruktor untuk menginisialisasi pin
StepperMotor::StepperMotor(int pin1, int pin2, int pin3, int pin4)
    : _pin1(pin1), _pin2(pin2), _pin3(pin3), _pin4(pin4), _currentStep(0), _previousMillis(0), _interval(2)
{
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    pinMode(_pin3, OUTPUT);
    pinMode(_pin4, OUTPUT);
}

// Fungsi untuk mengatur kecepatan motor (interval antar langkah)
void StepperMotor::setSpeed(unsigned long interval)
{
    _interval = interval;
}

// Fungsi untuk melakukan satu langkah
void StepperMotor::oneStep(bool dir)
{
    if (dir)
    {
        switch (_currentStep)
        {
        case 0:
            digitalWrite(_pin1, HIGH);
            digitalWrite(_pin2, LOW);
            digitalWrite(_pin3, LOW);
            digitalWrite(_pin4, LOW);
            break;
        case 1:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, HIGH);
            digitalWrite(_pin3, LOW);
            digitalWrite(_pin4, LOW);
            break;
        case 2:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, LOW);
            digitalWrite(_pin3, HIGH);
            digitalWrite(_pin4, LOW);
            break;
        case 3:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, LOW);
            digitalWrite(_pin3, LOW);
            digitalWrite(_pin4, HIGH);
            break;
        }
    }
    else
    {
        switch (_currentStep)
        {
        case 0:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, LOW);
            digitalWrite(_pin3, LOW);
            digitalWrite(_pin4, HIGH);
            break;
        case 1:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, LOW);
            digitalWrite(_pin3, HIGH);
            digitalWrite(_pin4, LOW);
            break;
        case 2:
            digitalWrite(_pin1, LOW);
            digitalWrite(_pin2, HIGH);
            digitalWrite(_pin3, LOW);
            digitalWrite(_pin4, LOW);
            break;
        case 3:
            digitalWrite(_pin1, HIGH);
            digitalWrite(_pin2, LOW);
            digitalWrite(_pin3, LOW);
            digitalWrite(_pin4, LOW);
            break;
        }
    }

    _currentStep++;
    if (_currentStep > 3)
    {
        _currentStep = 0;
    }
}

// Fungsi untuk memutar motor sejumlah langkah tertentu
void StepperMotor::stepMotor(int steps, bool dir)
{
    for (int i = 0; i < steps; i++)
    {
        oneStep(dir);
        delay(2);
    }
}
