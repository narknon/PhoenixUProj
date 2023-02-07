#include "AvaMotionWarpingModifier_Warp.h"

FAvaMotionWarpingModifier_Warp::FAvaMotionWarpingModifier_Warp() {
    this->bWarpTranslation = false;
    this->bDisallowHorizontalStretching = false;
    this->bDisallowHorizontalSquishing = false;
    this->bIgnoreZAxis = false;
    this->bWarpRotation = false;
    this->RotationType = EMotionWarpRotationType::Default;
    this->WarpRotationTimeMultiplier = 0.00f;
}

