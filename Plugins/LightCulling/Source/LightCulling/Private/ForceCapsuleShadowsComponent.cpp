#include "ForceCapsuleShadowsComponent.h"

class AActor;
class UForceCapsuleShadowsComponent;

void UForceCapsuleShadowsComponent::UpdateSettings(FForceCapsuleShadowsSettings NewSettings) {
}

void UForceCapsuleShadowsComponent::Enabled(bool& bEnabled) {
}

void UForceCapsuleShadowsComponent::Enable(bool bEnable) {
}

void UForceCapsuleShadowsComponent::DetachAndDestroyForceCapsuleShadows(AActor* Owner, UForceCapsuleShadowsComponent* ExistingForceCapsuleShadowsComponent) {
}

void UForceCapsuleShadowsComponent::DestroyForceCapsuleShadows() {
}

void UForceCapsuleShadowsComponent::CreateAndAttachForceCapsuleShadows(AActor* Owner, FForceCapsuleShadowsSettings NewSettings, UForceCapsuleShadowsComponent*& NewForceCapsuleShadowsComponent, bool bTransient) {
}

UForceCapsuleShadowsComponent::UForceCapsuleShadowsComponent() {
    this->bDisable = false;
}

