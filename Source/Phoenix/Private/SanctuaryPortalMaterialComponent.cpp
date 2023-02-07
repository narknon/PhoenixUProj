#include "SanctuaryPortalMaterialComponent.h"

class UObject;

void USanctuaryPortalMaterialComponent::OnUpdateIdentity(ESanctuaryIdentity PreviousIdentity, ESanctuaryIdentity CurrentIdentity, float BlendWeight) {
}

void USanctuaryPortalMaterialComponent::OnUpdateEntranceMaterials(const UObject* InCaller) {
}

USanctuaryPortalMaterialComponent::USanctuaryPortalMaterialComponent() {
    this->bSeparateSettingsForPreRenderedCubemap = false;
}

