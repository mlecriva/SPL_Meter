#include <WiFi.h>
#include <FTPClient.h>
#include "network_config.h"
#include <iostream>

using namespace std;

FTPClient ftp(ftp_server, ftp_username, ftp_password);

static bool file_created = false;

void setup()
{
    Serial.begin(115200);

    if (!WiFi.config(local_IP, gateway, subnet))
    {
        cout << "STA Failed to configure" << endl;
    }
    else
    {
        cout << "Success to configure STA :" << endl;
        cout << "Local IP address   : " << local_IP << endl;
        cout << "Gateway IP address : " << gateway << endl;
        cout << "Subnet IP address  : " << subnet << endl;
    }

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

    ftp.connect();
}

void loop()
{
    delay(1000);
    if (!file_created)
    {

        ftp.createFile("hello_world.txt", TYPE_A);
        ftp.write("Hello World");
        ftp.closeFile();
        ftp.stop();
        file_created = true;
    }
}