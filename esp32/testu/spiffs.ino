#include "FileManager.h"

/* You only need to format SPIFFS the first time you run a
    test or else use the SPIFFS plugin to create a partition
    https://github.com/me-no-dev/arduino-esp32fs-plugin */
#define FORMAT_SPIFFS_IF_FAILED true

FileManager fm(SPIFFS);

void setup()
{
    Serial.begin(115200);
    fm.begin();
    fm.write("/test.txt", "hello world \n");

    String data;

    data = fm.getFileContent("/test.txt");

    fm.ls("/", 0);

    Serial.print(data);
}

void loop()
{
}