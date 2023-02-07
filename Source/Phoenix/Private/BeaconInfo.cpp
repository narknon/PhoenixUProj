#include "BeaconInfo.h"

class AActor;

void UBeaconInfo::SetupChestBeacon(const FString& pBeaconName, FVector pLocation, AActor* pParentActor) {
}

UBeaconInfo::UBeaconInfo() {
    this->BeaconType = EBeaconType::BEACONTYPE_NONE;
    this->BeaconSubType = EBeaconSubType::BEACONSUBTYPE_NONE;
    this->LastBeaconType = EBeaconType::BEACONTYPE_NONE;
    this->BeaconHandle = 0;
    this->ActivationDistance = 0;
    this->EnterExitDistance = 0;
    this->DisplayPriority = 0;
    this->bIsBeaconActive = true;
    this->BeaconFlags = 0;
    this->BeaconScale = 1.00f;
    this->bHudIconSuppressed = false;
    this->bHasTracedInGameWorld = false;
    this->BeaconRuntimeFlags = 0;
    this->InEnterExitZone = false;
    this->LastTransitionListIndex = 0;
    this->BeaconState = EBeaconState::BEACONSTATE_UNDISCOVERED;
}

