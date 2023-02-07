#include "DynamicTrackedLocation.h"

ADynamicTrackedLocation::ADynamicTrackedLocation() {
    this->bRegisterOnCreation = true;
    this->bDrawDebug = false;
    this->debugRadius = 50.00f;
    this->debugSegments = 16;
}

