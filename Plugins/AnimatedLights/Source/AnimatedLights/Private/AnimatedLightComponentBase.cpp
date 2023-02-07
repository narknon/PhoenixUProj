#include "AnimatedLightComponentBase.h"

void UAnimatedLightComponentBase::IsAnimatedLightEnabled(bool& bIsEnabled) const {
}

void UAnimatedLightComponentBase::EnableAnimatedLight(bool bEnable) {
}

void UAnimatedLightComponentBase::DisableAnimatedLight() {
}

UAnimatedLightComponentBase::UAnimatedLightComponentBase() {
    this->StartOffset = 0.00f;
    this->DurationScale = 1.00f;
    this->bDeepScanChildren = true;
    this->bEnabled = true;
    this->RandomizeStartOffset = false;
    this->Time = 0.00f;
}

