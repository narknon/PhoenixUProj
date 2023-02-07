#include "SendTargetComponent.h"

class AActor;
class UPrimitiveComponent;

void USendTargetComponent::SetSendTargetPriority(uint8 InPriority) {
}

void USendTargetComponent::SetEnabled(bool bInEnabled) {
}

bool USendTargetComponent::IsEnabled() const {
    return false;
}

uint8 USendTargetComponent::GetSendTargetPriority() const {
    return 0;
}

void USendTargetComponent::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

USendTargetComponent::USendTargetComponent() {
    this->Priority = 5;
    this->bEnabled = true;
    this->bDetectsCollision = false;
    this->Radius = 100.00f;
    this->Damage = 0.00f;
    this->bDisableWhenHit = false;
    this->bOnlyHitByTargetingActor = false;
}

