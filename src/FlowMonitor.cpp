#include "FlowMonitor.h"

FlowMonitor::FlowMonitor(const char* feed,
                         FlowMeter& meter,
                         AdafruitIOHandler& aioHandler)
    : feed(feed),
      flow_meter(meter),
      aio(aioHandler)
{
}