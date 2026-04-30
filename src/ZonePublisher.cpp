#include "ZonePublisher.h"

ZonePublisher::ZonePublisher(Zone &z, AdafruitIO_Feed &f) 
    : zone(z),
      feed(f)
{
}

void ZonePublisher::publish() {
    feed.save(zone.liters());
}