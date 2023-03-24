#include "RaceGate.h"


void ARaceGate::OnMissGate(bool& bSuccess) {
}

void ARaceGate::OnHitGate(bool& bSuccess) {
}



bool ARaceGate::IsGateActive() const {
    return false;
}

FVector ARaceGate::GetSplineTrackOffset_Implementation() {
    return FVector{};
}

ARaceGate::ARaceGate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OwningRace = NULL;
}

