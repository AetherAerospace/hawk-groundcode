/*
    Web Interface API
*/

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include "util/Serial.h"
#include "util/OLED.h"
#include "WebAPI.h"

// start webserver on port 80
AsyncWebServer server(80);

// handle main webinterface
void initWeb(){
    server.on("/api", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "Hello API!");
    });
    server.begin();
    srlInfo("Web", "Initialized");
    writeToDisplay("Web", "Initialized");
}
