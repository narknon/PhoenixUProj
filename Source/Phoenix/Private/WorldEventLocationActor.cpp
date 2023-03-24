#include "WorldEventLocationActor.h"

class UWorldEventCondition;
class UWorldEventSocketComponent;

bool AWorldEventLocationActor::UseForcedWorldEventSubset() const {
    return false;
}

bool AWorldEventLocationActor::UseForcedWorldEventName() const {
    return false;
}

void AWorldEventLocationActor::StreamingHandle() {
}

void AWorldEventLocationActor::SetLocatorName(const FName& Name) {
}

UWorldEventSocketComponent* AWorldEventLocationActor::RequestSocket(const FGameplayTagContainer& SocketDescriptors) {
    return NULL;
}

void AWorldEventLocationActor::ReleaseAllSockets() {
}

void AWorldEventLocationActor::OnEventNaturalEnd() {
}

void AWorldEventLocationActor::MarkEventAsCompleted() {
}

int32 AWorldEventLocationActor::GetPercentChanceOfBeingSelected() const {
    return 0;
}

int32 AWorldEventLocationActor::GetNumberOfSockets() const {
    return 0;
}

FName AWorldEventLocationActor::GetLocatorName() const {
    return NAME_None;
}

FGameplayTagContainer AWorldEventLocationActor::GetLocationDescriptors() const {
    return FGameplayTagContainer{};
}

FName AWorldEventLocationActor::GetForcedWorldEventSubset() const {
    return NAME_None;
}

FName AWorldEventLocationActor::GetForcedWorldEventName() const {
    return NAME_None;
}

TArray<TSoftObjectPtr<UWorldEventCondition>> AWorldEventLocationActor::GetConditions() const {
    return TArray<TSoftObjectPtr<UWorldEventCondition>>();
}

AWorldEventLocationActor::AWorldEventLocationActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PercentChanceOfBeingSelected = 100;
    this->StreamInDistance = 10000.00f;
    this->StreamOutDistance = 14000.00f;
    this->bOverrideDefaultCooldown = false;
    this->bInfiniteCooldown = false;
    this->bSpawnEventWithLevel = false;
    this->bMissionCritical = false;
    this->bDrawStreamingVolume = false;
    this->bUseForcedWorldEventName = false;
    this->bUseForcedWorldEventSubset = false;
}

