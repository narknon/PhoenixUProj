#include "FastTravelLocation.h"

void AFastTravelLocation::Unlock() {
}

void AFastTravelLocation::SetAvailable(bool availableIn) {
}

void AFastTravelLocation::Lock() {
}



bool AFastTravelLocation::GetAvailable() {
    return false;
}

void AFastTravelLocation::AdjustCogTargetPoint(FVector Location) {
}

void AFastTravelLocation::AdjustBeaconWorldLocation(const FString& Name, const FVector& WorldLocation) {
}


AFastTravelLocation::AFastTravelLocation() {
    this->bIsSaveLocation = false;
}

