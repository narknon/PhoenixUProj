#include "CelestialPointOfInterestEntry.h"

FCelestialPointOfInterestEntry::FCelestialPointOfInterestEntry() {
    this->Type = ECelestialPointOfInterestType::Unknown;
    this->RightAscentionHours = 0.00f;
    this->RightAscentionMinutes = 0.00f;
    this->RightAscentionSeconds = 0.00f;
    this->DeclinationDegrees = 0.00f;
    this->DeclinationMinutes = 0.00f;
    this->DeclinationSeconds = 0.00f;
}

