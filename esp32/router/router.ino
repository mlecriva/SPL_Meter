#include <WiFi.h>
#include "network_config.h"
#include <iostream>

using namespace std;

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);

    cout << "Setting AP (Access Point)… " << endl;

    WiFi.softAP(ssid, password);

    server.begin();
}

void loop()
{
}