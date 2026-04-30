#pragma once

#include "AdafruitIO_WiFi.h"
#include "config.h"

class AdafruitIOHandler {
    private:
    AdafruitIO_WiFi &io;

    public:
    AdafruitIOHandler(AdafruitIO_WiFi &ioRef);

    void publish(const char* feed, float value);
};