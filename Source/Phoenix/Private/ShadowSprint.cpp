#include "ShadowSprint.h"

class UCapsuleComponent;

void AShadowSprint::SetScaleInfo(bool bInScaleIn, float InActiveScale) {
}

UCapsuleComponent* AShadowSprint::GetCapsuleComponent() {
    return NULL;
}

AShadowSprint::AShadowSprint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActiveScale = 1.00f;
    this->bScaleIn = true;
    this->CapsuleComponent = NULL;
    this->MovementComponent = NULL;
}

