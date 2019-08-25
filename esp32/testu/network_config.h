#ifndef __NETWORK_CONFIG_H__
#define __NETWORK_CONFIG_H__

#include <WiFi.h>

const char *ssid = "ESP32-Access-Point";
const char *password = "123456789";

// Static IP address
const IPAddress local_IP(192, 168, 1, 2);
// Gateway IP address
const IPAddress gateway(192, 168, 1, 1);
// subnet IP address
const IPAddress subnet(255, 255, 0, 0);

// Broadcast
const IPAddress udpServer_IP = (192, 168, 1, 255);
// UDP port
const int udpPort = 44444;

char *ftp_server = "...";
char *ftp_username = "...";
char *ftp_password = "...";

#endif /* __NETWORK_CONFIG_H__ */