#include "TransformationOverlandComponent.h"

class AActor;

void UTransformationOverlandComponent::OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

void UTransformationOverlandComponent::HealthZero(AActor* InActor) {
}

UTransformationOverlandComponent::UTransformationOverlandComponent() {
    this->newActor = NULL;
}

