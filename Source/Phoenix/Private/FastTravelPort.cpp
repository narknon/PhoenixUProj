#include "FastTravelPort.h"

AFastTravelPort::AFastTravelPort(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DestinationPort = NULL;
    this->DelayBeforeTeleport = 0.00f;
}

