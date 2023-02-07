#include "SanctuaryLightingIdentityMasterComponent.h"

class UObject;
class USanctuaryLightingIdentityMasterComponent;

void USanctuaryLightingIdentityMasterComponent::SetIdentity(ESanctuaryIdentity InNewIdentity, float InBlendDuration) {
}

ESanctuaryIdentity USanctuaryLightingIdentityMasterComponent::GetPreviousIdentity() const {
    return ESanctuaryIdentity::Default;
}

USanctuaryLightingIdentityMasterComponent* USanctuaryLightingIdentityMasterComponent::GetLightingIdentityMaster(const UObject* WorldContextObject) {
    return NULL;
}

float USanctuaryLightingIdentityMasterComponent::GetIdentityBlendWeight() const {
    return 0.0f;
}

ESanctuaryIdentity USanctuaryLightingIdentityMasterComponent::GetCurrentIdentity() const {
    return ESanctuaryIdentity::Default;
}

USanctuaryLightingIdentityMasterComponent::USanctuaryLightingIdentityMasterComponent() {
    this->CurrentIdentity = ESanctuaryIdentity::Default;
    this->PreviousIdentity = ESanctuaryIdentity::Default;
}

