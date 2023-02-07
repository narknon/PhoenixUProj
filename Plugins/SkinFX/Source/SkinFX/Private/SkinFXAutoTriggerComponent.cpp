#include "SkinFXAutoTriggerComponent.h"

class AActor;
class UObject;
class USkinFXAutoTriggerDriver;

void USkinFXAutoTriggerComponent::SetEnabled(bool Enabled) {
}

void USkinFXAutoTriggerComponent::RemoveDriverByName(FName TriggerName) {
}

void USkinFXAutoTriggerComponent::RemoveDriver(const USkinFXAutoTriggerDriver* Driver) {
}

void USkinFXAutoTriggerComponent::RefreshAll(UObject* WorldContextObject) {
}

void USkinFXAutoTriggerComponent::Refresh(AActor* Actor) {
}

bool USkinFXAutoTriggerComponent::IsEnabled() const {
    return false;
}

bool USkinFXAutoTriggerComponent::HasDriverByName(FName TriggerName) const {
    return false;
}

bool USkinFXAutoTriggerComponent::HasDriver(const USkinFXAutoTriggerDriver* Driver) const {
    return false;
}

void USkinFXAutoTriggerComponent::AddDriver(const USkinFXAutoTriggerDriver* Driver) {
}

USkinFXAutoTriggerComponent::USkinFXAutoTriggerComponent() {
    this->bDisabled = false;
}

