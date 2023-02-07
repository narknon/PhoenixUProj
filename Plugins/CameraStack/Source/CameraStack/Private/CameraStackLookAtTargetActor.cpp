#include "CameraStackLookAtTargetActor.h"

class AActor;

void ACameraStackLookAtTargetActor::StopPlayerInitiation(int32 PlayerIndex) {
}

void ACameraStackLookAtTargetActor::StartPlayerInitiation(int32 PlayerIndex) {
}

void ACameraStackLookAtTargetActor::OnTriggerEndOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

void ACameraStackLookAtTargetActor::OnTriggerBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

bool ACameraStackLookAtTargetActor::IsPlayerInitiationActive(int32 PlayerIndex) const {
    return false;
}

bool ACameraStackLookAtTargetActor::IsActiveLookAtTargetForPlayer(int32 PlayerIndex) const {
    return false;
}

void ACameraStackLookAtTargetActor::DeactivateLookAt(int32 PlayerIndex) {
}

void ACameraStackLookAtTargetActor::ActivateLookAt(int32 PlayerIndex, float Duration) {
}

ACameraStackLookAtTargetActor::ACameraStackLookAtTargetActor() {
    this->LookAtStrength = ECameraStackLookAtStrength::Strong;
    this->TimeoutAfterTriggerEntered = 0.00f;
    this->bTriggerOnReEntry = true;
}

