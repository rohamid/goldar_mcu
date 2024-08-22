#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Arduino.h>

class StepperMotor
{
public:
    StepperMotor(int pin1, int pin2, int pin3, int pin4);
    void setSpeed(unsigned long interval);
    void stepMotor(int steps, bool dir);

private:
    void oneStep(bool dir);

    int _pin1, _pin2, _pin3, _pin4;
    int _currentStep;
    unsigned long _previousMillis;
    unsigned long _interval;
};

#endif
