#include "SendTarget.h"
#include "Components/SphereComponent.h"

class AActor;
class UPrimitiveComponent;

void ASendTarget::SetSendTargetPriority(uint8 InPriority) {
}

void ASendTarget::SetEnabled(bool bInEnabled) {
}

bool ASendTarget::IsEnabled() const {
    return false;
}

uint8 ASendTarget::GetSendTargetPriority() const {
    return 0;
}

void ASendTarget::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

ASendTarget::ASendTarget() {
    this->SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    this->Priority = 5;
    this->bEnabled = true;
    this->bDetectsCollision = false;
    this->Radius = 100.00f;
    this->bDisableWhenHit = false;
    this->bOnlyHitByTargetingActor = false;
}

