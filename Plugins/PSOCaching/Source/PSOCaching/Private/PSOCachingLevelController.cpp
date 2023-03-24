#include "PSOCachingLevelController.h"

APSOCachingLevelController::APSOCachingLevelController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CameraRotationSpeed = 0.00f;
    this->DebugFastAssetsCount = 0;
    this->Mode = EPSOCachingLevelMode::Regular;
}

