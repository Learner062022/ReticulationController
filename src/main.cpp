#include <Arduino.h>
#include <AdafruitIO_WiFi.h>
#include "FlowMeter.h"
#include "config.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

AdafruitIO_Feed *meter1Feed = io.feed("zone1");

FlowMeter meter1;

void IRAM_ATTR onPulse() {
    meter1.pulse();
}

void setup() {
    Serial.begin(115200);

    pinMode(12, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(12), onPulse, RISING);

    while (io.status() < AIO_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("\nConnected to Adafruit IO!");
}

void loop() {
    io.run();

    meter1Feed->save(meter1.liters());

    delay(1000);
}