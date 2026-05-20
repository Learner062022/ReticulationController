#include <Arduino.h>
#include <AdafruitIO_WiFi.h>
#include "config.h"
#include "controller.h"
#include "fake_zone.h"
#include "fake_flow_meter.h"
#include <array>

FakeFlowMeter fakeFlow;

FakeZone masterZone = FakeZone();
FakeZone zone1 = FakeZone(10);
FakeZone zone2 = FakeZone(10);
FakeZone zone3 = FakeZone(10);
FakeZone zone4 = FakeZone(10);

std::array<IZone*, 4> zones = {
    &zone1,
    &zone2,
    &zone3,
    &zone4
};

Controller controller(zones, &masterZone, fakeFlow);

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
AdafruitIO_Feed* waterFeed = io.feed("reticulationcontroller.total-usage");

unsigned long lastPublish = 0;
constexpr unsigned long PUBLISH_INTERVAL_MS = 5000;

void publishIfDue() {
    unsigned long now = millis();

    if (now - lastPublish < PUBLISH_INTERVAL_MS) return;
    
    lastPublish = now;
    waterFeed->save(controller.getUsedLiters());
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

// Simulation note:
// In simulation builds, synthetic flow must be injected so controller logic and telemtry advance.
// Real hardware increments flow via the YFS201 ISR, so no manual flow injection is required here.
void loop() {
    io.run();
    controller.update();
    publishIfDue();
}