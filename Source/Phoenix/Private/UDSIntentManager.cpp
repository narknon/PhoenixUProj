#include "UDSIntentManager.h"

void UUDSIntentManager::HandleUDSFastTravelFinished() {
}

void UUDSIntentManager::HandleOnCurtainsRaised() {
}

void UUDSIntentManager::HandleNavigationPathUpdated(TArray<FVector> NewPath) {
}

void UUDSIntentManager::HandleMissionOnCurtainsRaised() {
}

UUDSIntentManager::UUDSIntentManager() {
    this->UDSActivityManager = NULL;
}

