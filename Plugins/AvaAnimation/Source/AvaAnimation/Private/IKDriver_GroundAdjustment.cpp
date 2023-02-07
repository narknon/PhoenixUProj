#include "IKDriver_GroundAdjustment.h"

UIKDriver_GroundAdjustment::UIKDriver_GroundAdjustment() {
    this->TraceChannel = ECC_WorldStatic;
    this->TranslationInterpSpeed = 20.00f;
    this->RotationInterpSpeed = 2.00f;
    this->MaxTranslationAdjustmentSpeed = 300.00f;
    this->bEnableRetargeting = false;
    this->bEnableAnticipation = true;
    this->MaxReachAdjustmentAngle = 90.00f;
    this->ReachAdjustToLowestOrHighest = 0.25f;
    this->TraceDelayRangePerLOD.AddDefaulted(4);
    this->StrideWarpSpringHalflife = 0.25f;
    this->GroundNormalSpringHalflife = 0.08f;
}

