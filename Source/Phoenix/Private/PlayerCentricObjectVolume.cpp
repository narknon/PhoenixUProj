#include "PlayerCentricObjectVolume.h"
#include "ManualNavigationInvokerComponent.h"

class AActor;

void APlayerCentricObjectVolume::SetSpawnBoundsFromVectors(const FVector& Min, const FVector& Max) {
}

void APlayerCentricObjectVolume::SetSpawnBounds(const FBox& SpawnBounds) {
}

void APlayerCentricObjectVolume::SetEnableSpawning(bool bSpawningEnabled, bool bCullActive) {
}

void APlayerCentricObjectVolume::SetAllowAutoActivation(bool bAllowAutoActivate) {
}

void APlayerCentricObjectVolume::OnFinishedSpawning(const FName& GroupName) {
}

void APlayerCentricObjectVolume::OnActorSpawned(AActor* SpawnedActor, const FName& GroupName) {
}

void APlayerCentricObjectVolume::ObjectLoaded() {
}

bool APlayerCentricObjectVolume::HasSpawned() {
    return false;
}

FVector APlayerCentricObjectVolume::GetVolumeExtents() {
    return FVector{};
}

FBox APlayerCentricObjectVolume::GetVolumeBounds() {
    return FBox{};
}

FBox APlayerCentricObjectVolume::GetSpawnBounds() {
    return FBox{};
}

int32 APlayerCentricObjectVolume::GetSpawnActorCount() {
    return 0;
}

int32 APlayerCentricObjectVolume::GetAliveActorCount() {
    return 0;
}

int32 APlayerCentricObjectVolume::GetActiveActorCount() {
    return 0;
}

void APlayerCentricObjectVolume::ForceDeactivate() {
}

void APlayerCentricObjectVolume::ForceActivate() {
}

bool APlayerCentricObjectVolume::DoneSpawning() {
    return false;
}

APlayerCentricObjectVolume::APlayerCentricObjectVolume() {
    this->bShowActivationDistances = false;
    this->bEnableAutoActivation = true;
    this->TriggerDistance = 1000.00f;
    this->CullDistance = 1500.00f;
    this->bEnableSpawning = true;
    this->ExtentsPercentageForDefaultSpawnLocation = 100.00f;
    this->RespawnDistance = 5000.00f;
    this->PlayerOffsetForDefaultSpawnLocation = 1500.00f;
    this->SpawnVolumeType = ESpawnVolumeType::Box;
    this->VolumeComponent = NULL;
    this->NavInvokerComponent = CreateDefaultSubobject<UManualNavigationInvokerComponent>(TEXT("NavInvokerComponent"));
}

