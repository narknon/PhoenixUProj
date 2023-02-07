#include "SkyStateOverrideCelestialPointOfInterestAlignTo.h"

void USkyStateOverrideCelestialPointOfInterestAlignTo::SetPointOfInterestName(FName NewPointOfInterest) const {
}

void USkyStateOverrideCelestialPointOfInterestAlignTo::SetPointOfInterest(FCelestialPointOfInterestName NewPointOfInterest) const {
}

void USkyStateOverrideCelestialPointOfInterestAlignTo::GetPointOfInterestName(FName& CurrentPointOfInterest) const {
}

void USkyStateOverrideCelestialPointOfInterestAlignTo::GetPointOfInterest(FCelestialPointOfInterestName& CurrentPointOfInterest) const {
}

USkyStateOverrideCelestialPointOfInterestAlignTo::USkyStateOverrideCelestialPointOfInterestAlignTo() {
    this->Priority = 0.00f;
    this->bUseSlerp = true;
    this->bEnabled = true;
}

