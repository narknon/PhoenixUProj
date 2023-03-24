#include "AvaLevelStreamingVolumeSet.h"

class ULevelStreamingDynamic;

void AAvaLevelStreamingVolumeSet::SetShouldBeVisible(bool InShouldBeVisible) {
}

void AAvaLevelStreamingVolumeSet::SetShouldBeLoaded(bool InShouldBeLoaded) {
}

TArray<float> AAvaLevelStreamingVolumeSet::GetLODDistances() {
    return TArray<float>();
}

ULevelStreamingDynamic* AAvaLevelStreamingVolumeSet::GetLoadedLevel() {
    return NULL;
}

FRotator AAvaLevelStreamingVolumeSet::GetLevelRot() {
    return FRotator{};
}

FVector AAvaLevelStreamingVolumeSet::GetLevelLoc() {
    return FVector{};
}

void AAvaLevelStreamingVolumeSet::ForceUnload() {
}

void AAvaLevelStreamingVolumeSet::ForceLoad() {
}

AAvaLevelStreamingVolumeSet::AAvaLevelStreamingVolumeSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsExterior = false;
    this->bExemptFromInteriorExteriorCulling = false;
    this->bSwapsPrecomputedVisibility = false;
    this->DependentLevelAdditionalBoundsRadius = 0.00f;
    this->LevelPlacementActor = NULL;
    this->bShouldDitherLODTransitions = true;
    this->LoadedLevel = NULL;
}

