#include "FileManager.h"

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