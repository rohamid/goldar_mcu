#include <StepperMotor.h>

// Definisikan pin yang akan digunakan untuk motor stepper
#define STEPPER_PIN_1 2
#define STEPPER_PIN_2 3
#define STEPPER_PIN_3 4
#define STEPPER_PIN_4 5
#define STEPPER_LIMIT_PIN 23
bool CloseFull = false;

// Buat instance dari class StepperMotor
StepperMotor motor(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);

void setup()
{
    Serial.begin(115200);
    delay(2000); // Berikan jeda 2 detik sebelum memulai program
}

void loop()
{

    do
    {
        CloseFull = digitalRead(STEPPER_LIMIT_PIN);
        motor.stepMotor(10, false);
    } while (!CloseFull);
    delay(3000);

    motor.stepMotor(12000, true);
    delay(3000);

    motor.stepMotor(7200, false);
    delay(3000);

    ;
}
