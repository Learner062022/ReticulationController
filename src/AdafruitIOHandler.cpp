#include "AdafruitIOHandler.h"

AdafruitIOHandler::AdafruitIOHandler(AdafruitIO_WiFi& ioRef)
    : io(ioRef)
{
}

void AdafruitIOHandler::publish(const char* feed, float value)
{
    io.feed(feed)->save(value);
}