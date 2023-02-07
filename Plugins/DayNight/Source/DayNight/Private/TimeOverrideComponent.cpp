#include "TimeOverrideComponent.h"

void UTimeOverrideComponent::Valid(bool& bValid) const {
}

void UTimeOverrideComponent::SetLerpAlpha(float LerpAlpha) {
}

void UTimeOverrideComponent::SetEnabled(bool bEnable) {
}

void UTimeOverrideComponent::IsEnabled(bool& bEnable) const {
}

void UTimeOverrideComponent::HasLerpAlpha(bool& bHasLerpAlpha) const {
}

void UTimeOverrideComponent::GetLerpAlpha(float& LerpAlpha) const {
}

void UTimeOverrideComponent::DisableLerpAlpha() {
}

void UTimeOverrideComponent::CanUseLerpAlpha(bool& bUseLerpAlpha) const {
}

UTimeOverrideComponent::UTimeOverrideComponent() {
    this->TimeOverride = NULL;
    this->bEnabled = true;
    this->ComponentLerpAlpha = -1.00f;
}

