#include "PhysicalResponseConfig.h"

UPhysicalResponseConfig::UPhysicalResponseConfig() {
    this->bLockXRotation = false;
    this->bLockYRotation = false;
    this->bLockZRotation = false;
    this->bLockXRotationPositive = false;
    this->bLockXRotationNegative = false;
    this->bLockYRotationPositive = false;
    this->bLockYRotationNegative = false;
    this->bLockZRotationPositive = false;
    this->bLockZRotationNegative = false;
    this->bLockXTranslation = false;
    this->bLockYTranslation = false;
    this->bLockZTranslationUp = false;
    this->bLockZTranslationDown = false;
    this->bScaleAdditive = true;
    this->AudioMinScaleThreshold = 0.50f;
}

