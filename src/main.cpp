
#include <Arduino.h>
#include "MFEEPROM.h"

#define CLEARBYTE 0xFF;

MFEEPROM MFeeprom;

void setup()
{
    MFeeprom.init();
    uint16_t bufferlength = MFeeprom.get_length();
    char     buffer[bufferlength];
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    for (uint16_t i = 0; i < bufferlength; i++) {
        buffer[i] = CLEARBYTE;
    }
    if (MFeeprom.write_block(0, buffer, bufferlength)) {
    }
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
