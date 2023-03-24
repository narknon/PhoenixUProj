#include "PointOfInterestMarkup.h"

APointOfInterestMarkup::APointOfInterestMarkup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DiscoverDistance = 0.00f;
    this->State = EPointOfInterestState::Found;
}

