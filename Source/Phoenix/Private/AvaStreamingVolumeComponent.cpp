#include "AvaStreamingVolumeComponent.h"

class ULevelStreamingDynamic;

void UAvaStreamingVolumeComponent::UpdateSeasonState() {
}

void UAvaStreamingVolumeComponent::SetShouldBeVisible(bool InShouldBeVisible) {
}

void UAvaStreamingVolumeComponent::SetShouldBeLoaded(bool InShouldBeLoaded) {
}

void UAvaStreamingVolumeComponent::SetLodTime(double InLodTime) {
}

void UAvaStreamingVolumeComponent::SetLodLevel(int32 InLodLevel) {
}

void UAvaStreamingVolumeComponent::ProposeLodLevel(int32 InLodLevel, FVector2D InBorderDist) {
}

void UAvaStreamingVolumeComponent::PropagateState() {
}

bool UAvaStreamingVolumeComponent::GetShouldBeVisible() {
    return false;
}

bool UAvaStreamingVolumeComponent::GetShouldBeLoaded() {
    return false;
}

int32 UAvaStreamingVolumeComponent::GetProposedLodLevel() {
    return 0;
}

double UAvaStreamingVolumeComponent::GetLodTime() {
    return 0.0;
}

int32 UAvaStreamingVolumeComponent::GetLodLevel() {
    return 0;
}

TArray<float> UAvaStreamingVolumeComponent::GetLODDistances() {
    return TArray<float>();
}

ULevelStreamingDynamic* UAvaStreamingVolumeComponent::GetLoadedLevel() {
    return NULL;
}

void UAvaStreamingVolumeComponent::ForceUnload() {
}

void UAvaStreamingVolumeComponent::ForceLoad() {
}

bool UAvaStreamingVolumeComponent::CommitLodLevel(double InLodTime) {
    return false;
}

UAvaStreamingVolumeComponent::UAvaStreamingVolumeComponent() {
    this->bIsExterior = false;
    this->bExemptFromInteriorExteriorCulling = false;
    this->bShouldDitherLODTransitions = true;
    this->DependentLevelAdditionalBoundsRadius = 0.00f;
    this->bSwapsPrecomputedVisibility = false;
    this->LodLevel = -1;
}

