#include "BlendDomainVisibilityComponentBase.h"

void UBlendDomainVisibilityComponentBase::SetEnabled(bool bNewEnabled) {
}

void UBlendDomainVisibilityComponentBase::ForceUpdate() {
}

UBlendDomainVisibilityComponentBase::UBlendDomainVisibilityComponentBase() {
    this->Threshold = 0.50f;
    this->bEnabled = true;
    this->LastBlend = -1.00f;
}

