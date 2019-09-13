#include <WiFi.h>
#include <NTPClient.h>
#include <FTPClient.h>
#include "FileManager.h"
#include "network_config.h"
#include <iostream>

using namespace std;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

/* FileManager instance */
FileManager fm(SPIFFS);

/* FTPClient instance */
FTPClient ftp(ftp_server, ftp_username, ftp_password, 2000);

/* FTPTask handler */
TaskHandle_t FTPTaskHandler;

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;

static void FTPTask(void *parameter);

void setup()
{
    Serial.begin(115200);

    // Connect to Wi-Fi network with SSID and password
    cout << "Connecting to " << ssid << endl;
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    cout << endl;

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        cout << "." << endl;
    }
    cout << endl;
    cout << "Connected to " << ssid << endl;
    cout << "IP address: " << WiFi.localIP() << endl;

    /* launch FileManager */
    fm.begin();

    timeClient.begin();

    /* connect the esp32 to the ftp server */
    ftp.connect();

    xTaskCreatePinnedToCore(
        FTPTask,         /* Function to implement the task */
        "FTPTask",       /* Name of the task */
        10000,           /* Stack size in words */
        NULL,            /* Task input parameter */
        0,               /* Priority of the task */
        &FTPTaskHandler, /* Task handle. */
        0);              /* Core where the task should run */
}

void loop()
{
    while (!timeClient.update())
    {
        timeClient.forceUpdate();
    }

    formattedDate = timeClient.getFormattedDate();
    Serial.println(formattedDate);

    vTaskDelay(10000 / portTICK_PERIOD_MS);
}

static void FTPTask(void *parameter)
{
    for (;;)
    {
        String fileName = formattedDate + ".txt";
        ftp.createFile(fileName.c_str(), TYPE_A);
        ftp.write(formattedDate.c_str());
        ftp.closeFile();
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}