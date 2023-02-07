#include "InteractionZoneComponent.h"

class AActor;
class UPrimitiveComponent;

void UInteractionZoneComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UInteractionZoneComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UInteractionZoneComponent::OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

UInteractionZoneComponent::UInteractionZoneComponent() {
}

