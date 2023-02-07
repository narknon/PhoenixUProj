#include "AblAnimationTagChooser_DirectionBased.h"

UAblAnimationTagChooser_DirectionBased::UAblAnimationTagChooser_DirectionBased() {
    this->NumAngles = 1;
    this->bWrapAngles = true;
    this->bSetFixedToDesiredDirection = true;
    this->bLeftFootAtEndOfList = true;
    this->NumSpeeds = 1;
    this->bUseFootPlacement = false;
    this->DirectionType = EDirectionType::ImpactDirection;
    this->bDebugDraw = false;
}

