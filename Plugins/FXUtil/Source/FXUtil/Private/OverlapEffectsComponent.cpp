#include "OverlapEffectsComponent.h"

class AActor;

void UOverlapEffectsComponent::ProcessHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void UOverlapEffectsComponent::ProcessEndOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

void UOverlapEffectsComponent::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

UOverlapEffectsComponent::UOverlapEffectsComponent() {
    this->HandlerDefinitions = NULL;
    this->CameraCutoffDistance = 50.00f;
    this->TrueSpeedRTPC = TEXT("TrueSpeedMS");
    this->TeleportThreshold = 2.50f;
    this->TrueSpeedRTPCThreshold = 0.10f;
    this->bUseCameraCutoffDistance = true;
    this->bSetTrueSpeedRTPC = true;
    this->bEnabled = true;
    this->LiveEvents = 0;
    this->LastTrueSpeed = 0.00f;
    this->bProcessEvents = false;
}

