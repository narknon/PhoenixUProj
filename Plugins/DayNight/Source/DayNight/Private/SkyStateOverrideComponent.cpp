#include "SkyStateOverrideComponent.h"

void USkyStateOverrideComponent::Valid(bool& bValid) const {
}

void USkyStateOverrideComponent::SetLerpAlpha(float LerpAlpha) {
}

void USkyStateOverrideComponent::SetEnabled(bool bEnable) {
}

void USkyStateOverrideComponent::IsEnabled(bool& bEnable) const {
}

void USkyStateOverrideComponent::HasLerpAlpha(bool& bHasLerpAlpha) const {
}

void USkyStateOverrideComponent::GetLerpAlpha(float& LerpAlpha) const {
}

void USkyStateOverrideComponent::DisableLerpAlpha() {
}

void USkyStateOverrideComponent::CanUseLerpAlpha(bool& bUseLerpAlpha) const {
}

USkyStateOverrideComponent::USkyStateOverrideComponent() {
    this->SkyStateOverride = NULL;
    this->bEnabled = true;
    this->ComponentLerpAlpha = -1.00f;
}

