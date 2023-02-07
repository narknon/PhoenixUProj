#include "AblAnimationModifier_WandCastAim.h"

UAblAnimationModifier_WandCastAim::UAblAnimationModifier_WandCastAim() {
    this->BoneName = TEXT("RightShoulder");
    this->EventName = TEXT("FireWand");
    this->DefaultInterpTime = 0.25f;
    this->bLoop = false;
    this->bAlwaysUseCurrentAimInfo = false;
    this->AimYawInterpSpeed = 0.00f;
    this->AimPitchInterpSpeed = 0.00f;
}

