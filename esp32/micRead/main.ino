#include <Arduino.h>
#include <MicReader.h>

MicReader mic(15);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.println("Hello Mic!");
    Serial.println(mic.readAnalog());
    delay(1000);
}
