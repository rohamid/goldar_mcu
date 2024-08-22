// library utama
#include <Arduino.h>

// declare indicatorLed
int redLed = 28;
int greenLed = 24;
int blueLed = 22;

// global variable indicatorLed
int delayTime = 250;

void init_blink()
{
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);
}

void blink()
{
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    Serial.println("hidup \tLED_BUILTIN ");
    delay(delayTime);               // wait for a second
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    Serial.println("mati \tLED_BUILTIN ");
    delay(delayTime); // wait for a second
    digitalWrite(redLed, HIGH);
    Serial.println("hidup \tredLed ");
    delay(delayTime);
    digitalWrite(redLed, LOW);
    Serial.println("mati \tredLed ");
    delay(delayTime);
    digitalWrite(greenLed, HIGH);
    Serial.println("hidup \tgreenLed ");
    delay(delayTime);
    digitalWrite(greenLed, LOW);
    Serial.println("mati \tgreenLed ");
    delay(delayTime);
    digitalWrite(blueLed, HIGH);
    Serial.println("hidup \tblueLed ");
    delay(delayTime);
    digitalWrite(blueLed, LOW);
    Serial.println("mati \tblueLed ");
    delay(delayTime);
    delay(delayTime); // wait for a second
}

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(115200);
    init_blink();
}

// the loop function runs over and over again forever
void loop()
{
    blink();
}
