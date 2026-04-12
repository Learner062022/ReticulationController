#pragma once

#include "FlowMeter.h"
#include "AdafruitIOHandler.h"

class FlowMonitor {
    private:
    FlowMeter& flow_meter;
    AdafruitIOHandler& aio;
    const char* feed;

    public:
    FlowMonitor(const char* feed, 
                FlowMeter& meter, 
                AdafruitIOHandler& aioHandler
    );
};