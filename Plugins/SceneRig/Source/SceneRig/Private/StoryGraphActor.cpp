#include "StoryGraphActor.h"
#include "Components/SceneComponent.h"

class AActor;
class UPrimitiveComponent;

bool AStoryGraphActor::TriggerEventOnActiveSceneRigs(FName Event) {
    return false;
}

bool AStoryGraphActor::TriggerEvent(FName Event, FName EventSource) {
    return false;
}

bool AStoryGraphActor::TriggerAnyEvent(FName& OutEventTriggered, FName EventSource) {
    return false;
}

bool AStoryGraphActor::SetBoolParameter(FName ParameterName, bool bBoolToSet) {
    return false;
}

void AStoryGraphActor::SetAllowTimeRigsToBeSkipped() {
}

bool AStoryGraphActor::SetActorParameter(FName ParameterName, AActor* ActorToSet) {
    return false;
}

void AStoryGraphActor::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AStoryGraphActor::OnCurtainRaised() {
}

void AStoryGraphActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool AStoryGraphActor::HandleEvent(FName Event, FStoryGraphDynamicEventHandler Handler) {
    return false;
}

AStoryGraphActor::AStoryGraphActor() {
    this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    this->StoryGraph = NULL;
    this->bHoldCurtainUntilPlay = false;
    this->ParameterBlock = NULL;
    this->bAllowTimeRigsToBeSkipped = false;
    this->AmbientPlayer = NULL;
}

