#include "FocusTrigger.h"

class AActor;
class UPrimitiveComponent;

void AFocusTrigger::SetTheReaction(SocialActionTypes InSocialAction) {
}

void AFocusTrigger::SetTheFocusProbablity(float InProbability) {
}

void AFocusTrigger::SetTheFocusOffset(FVector InFocusOffset) {
}

void AFocusTrigger::SetTheFocusActor(AActor* InFocusActor) {
}

void AFocusTrigger::SetTheEmotion(SocialSemanticIDs InEmotion) {
}

void AFocusTrigger::SetTheActionProbablity(float InProbability) {
}

void AFocusTrigger::SetPlayerFocusProbablity(float InProbability) {
}

void AFocusTrigger::SetPlayerActionProbablity(float InProbability) {
}

void AFocusTrigger::SetAbsoluteExtents(const FVector& InAbsoluteExtents) {
}

void AFocusTrigger::Deactivate() {
}

void AFocusTrigger::ActorOverlapEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AFocusTrigger::ActorOverlapBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo) {
}

void AFocusTrigger::Activate() {
}

AFocusTrigger::AFocusTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FocusTriggerType = FOCUSTRIGGER_TYPE_WORLDEVENT;
    this->StartInactive = false;
    this->TheFocusProbablity = 1.00f;
    this->TheActionProbablity = 1.00f;
    this->PlayerFocusProbablity = 1.00f;
    this->PlayerActionProbablity = 0.00f;
}

