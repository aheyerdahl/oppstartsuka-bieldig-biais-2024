#pragma once

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h> //library change: https://github.com/me-no-dev/ESPAsyncWebServer/blob/master/src/WebResponseImpl.h#L62

#include "Wire.h"

#define UP 0
#define DOWN 1

#define BLACK 0
#define WHITE 1

#define PROXIMITY 0
#define LINE 1
#define ENCODERS 2
#define GYRO 3
#define READ_TIME 4

typedef struct {
   int value;
   bool flag;
} dataPoint;

class Car {
 private:
   const char *ssid;
   const char *password;

 public:
   Car(char *ssid, char *password);
   static void notifyClients();
   static void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
   static void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
                       void *arg, uint8_t *data, size_t len);
   static void initWebSocket();
   void initCar();
   dataPoint data[5];
   void calibrateLine(bool lineColor);
   void calibrateGyro(uint16_t precision);
   void sendData(int graph, double data);
   void drive(int leftSpeed, int rightSpeed);
};

void w(bool knapp);
void a(bool knapp);
void s(bool knapp);
void d(bool knapp);
void q(bool knapp);
void e(bool knapp);

void triangle(bool knapp);
void circle(bool knapp);
void square(bool knapp);
