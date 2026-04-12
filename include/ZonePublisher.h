#pragma once

#include "Zone.h"
#include <AdafruitIO_WiFi.h>

class ZonePublisher {
private:
    Zone& zone;
    AdafruitIO_Feed& feed;

public:
    ZonePublisher(Zone& z, AdafruitIO_Feed& f); 
    void publish();
};