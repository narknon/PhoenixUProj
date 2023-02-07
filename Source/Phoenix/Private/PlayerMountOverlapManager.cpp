#include "PlayerMountOverlapManager.h"

class UPlayerMountOverlapManager;

bool UPlayerMountOverlapManager::IsInsideFacingEntry(bool bDraw) const {
    return false;
}

bool UPlayerMountOverlapManager::GetTimeInNoMountZone(float& Time) {
    return false;
}

bool UPlayerMountOverlapManager::GetInNoMountZone() const {
    return false;
}

UPlayerMountOverlapManager* UPlayerMountOverlapManager::Get() {
    return NULL;
}

bool UPlayerMountOverlapManager::CanSpeedUp() const {
    return false;
}

UPlayerMountOverlapManager::UPlayerMountOverlapManager() {
    this->SpeedUpUnavailableMessageTimeout = 1.50f;
    this->LandingUnavailableMessageTimeout = 1.50f;
}

