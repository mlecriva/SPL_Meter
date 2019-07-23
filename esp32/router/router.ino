#include <WiFi.h>

const char *ssid = "ESP32-Access-Point";
const char *password = "123456789";

// Static IP address
const IPAddress local_IP(192, 168, 1, 1);
// Gateway IP address
const IPAddress gateway(192, 168, 1, 1);
// subnet IP address
const IPAddress subnet(255, 255, 0, 0);

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);

    Serial.print("Setting AP (Access Point)… ");

    if (!WiFi.softAPConfig(local_IP, gateway, subnet))
    {
        Serial.println("STA Failed to configure");
    }
    else
    {
        Serial.println("Success to configure STA :");
        Serial.print("Local IP address   : ");
        Serial.println(local_IP);
        Serial.print("Gateway IP address : ");
        Serial.println(gateway);
        Serial.print("Subnet IP address  : ");
        Serial.println(subnet);
    }

    WiFi.softAP(ssid, password);

    server.begin();
}

void loop()
{
}