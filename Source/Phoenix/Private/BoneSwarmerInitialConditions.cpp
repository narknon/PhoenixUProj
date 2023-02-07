#include "BoneSwarmerInitialConditions.h"

FBoneSwarmerInitialConditions::FBoneSwarmerInitialConditions() {
    this->ProjectionType = FBoneSwarmProjectionType::UseCone;
    this->MinConeHalfAngle = 0.00f;
    this->MaxConeHalfAngle = 0.00f;
    this->MotionType = FCharacterBoneProjectionMotionType::Stationary;
    this->MinRotationSpeed = 0.00f;
    this->MaxRotationSpeed = 0.00f;
    this->MinTranslationPeriod = 0.00f;
    this->MaxTranslationPeriod = 0.00f;
    this->MinTranslationExtent = 0.00f;
    this->MaxTranslationExtent = 0.00f;
    this->MinCrawlingSpeed = 0.00f;
    this->MaxCrawlingSpeed = 0.00f;
    this->ShowType = FBoneSwarmShowType::Manual;
    this->MinHiddenTime = 0.00f;
    this->MaxHiddenTime = 0.00f;
    this->Offset = 0.00f;
    this->Scale = 0.00f;
    this->RandomizeScalePercent = 0.00f;
}

