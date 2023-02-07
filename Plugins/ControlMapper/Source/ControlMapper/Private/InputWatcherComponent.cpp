#include "InputWatcherComponent.h"

class AActor;
class UGameLogicObject;
class UStickFlickWatcherRecord;
class UWatcherRecord;

UGameLogicObject* UInputWatcherComponent::GetGameLogicObject() {
    return NULL;
}

FVector2D UInputWatcherComponent::GetFlickDirection(AActor* Owner, UStickFlickWatcherRecord* StickFlickWatcherRecord) {
    return FVector2D{};
}

void UInputWatcherComponent::FlushQueuedActionsOnOwner(AActor* Owner, UWatcherRecord* InWatcherRecord) {
}

void UInputWatcherComponent::FlushQueuedActions(UWatcherRecord* InWatcherRecord) {
}

UInputWatcherComponent::UInputWatcherComponent() {
    this->GameLogicObject = NULL;
}

