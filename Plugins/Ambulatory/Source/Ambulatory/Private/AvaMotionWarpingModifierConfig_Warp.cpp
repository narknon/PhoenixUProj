#include "AvaMotionWarpingModifierConfig_Warp.h"

class UAnimSequenceBase;
class UAvaMotionWarpWindowFinder;

void UAvaMotionWarpingModifierConfig_Warp::AddRootMotionModifierSimpleWarp(FAvaRootMotionWarper& InMotionWarper, UAvaMotionWarpWindowFinder* InWindowFinder, const UAnimSequenceBase* InAnimation, float InStartTime, float InEndTime, FName InSyncPointName, bool bInWarpTranslation, bool bInDisallowHorizontalStretching, bool bInDisallowHorizontalSquishing, bool bInIgnoreZAxis, bool bInWarpRotation, EMotionWarpRotationType InRotationType, float InWarpRotationTimeMultiplier) {
}

UAvaMotionWarpingModifierConfig_Warp::UAvaMotionWarpingModifierConfig_Warp() {
    this->bWarpTranslation = true;
    this->bDisallowHorizontalStretching = false;
    this->bDisallowHorizontalSquishing = false;
    this->bIgnoreZAxis = true;
    this->bWarpRotation = true;
    this->RotationType = EMotionWarpRotationType::Default;
    this->WarpRotationTimeMultiplier = 1.00f;
}

