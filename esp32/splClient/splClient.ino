#include <WiFi.h>
#include "network_config.h"
#include <iostream>

using namespace std;

//create UDP instance
WiFiUDP udpClient;

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
    cout <<"IP address: "<< WiFi.localIP() << endl;

    //This initializes udp and transfer buffer
    udpClient.begin(udpPort);
}

void loop()
{
}