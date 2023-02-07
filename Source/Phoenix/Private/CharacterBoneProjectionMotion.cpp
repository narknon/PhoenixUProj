#include "CharacterBoneProjectionMotion.h"

FCharacterBoneProjectionMotion::FCharacterBoneProjectionMotion() {
    this->MotionType = FCharacterBoneProjectionMotionType::Stationary;
    this->RotationSpeedDegreesPerSecond = 0.00f;
    this->TranslationPeriod = 0.00f;
    this->MaxExtent = 0.00f;
    this->CrawlingSpeed = 0.00f;
}

