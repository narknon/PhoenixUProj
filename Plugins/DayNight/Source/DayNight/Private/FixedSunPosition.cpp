#include "FixedSunPosition.h"

FFixedSunPosition::FFixedSunPosition() {
    this->Type = EFixedSunPositionType::Noon;
    this->AltitudeDegrees = 0.00f;
    this->AzimuthDegrees = 0.00f;
}

