#include <WiFi.h>
#include "network_config.h"
#include <iostream>

using namespace std;

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);

    cout << "Setting AP (Access Point)… " << endl;

    if (!WiFi.softAPConfig(local_IP, gateway, subnet))
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

    WiFi.softAP(ssid, password);

    server.begin();
}

void loop()
{
}