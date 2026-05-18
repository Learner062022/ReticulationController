#include <Arduino.h>
#include <AdafruitIO_WiFi.h>
#include "config.h"
#include "Controller.h"
#include <array>

std::array<Zone, 4> zones = {
    Zone(3, 1),
    Zone(4, 1),
    Zone(5, 1),
    Zone(6, 1)
};

Controller controller(zones, 2, 7);

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
AdafruitIO_Feed* waterFeed = io.feed("total_usage");

float totalLiters = 0.0f;

unsigned long lastPublish = 0;
constexpr unsigned long PUBLISH_INTERVAL_MS = 5000;

void publishIfDue() {
    unsigned long now = millis();

    if (now - lastPublish < PUBLISH_INTERVAL_MS) return;

    lastPublish = now;

    waterFeed->save(totalLiters);
}

void setup() {
    Serial.begin(115200);

    io.connect();

    while (io.status() < AIO_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("\nConnected to Adafruit IO");

    controller.startCycle();
}

void loop() {
    io.run();

    controller.update();
    
    publishIfDue();
}