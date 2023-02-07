#include "AvaTileRegionVolumeComponent.h"

void UAvaTileRegionVolumeComponent::RemoveTiles() {
}

void UAvaTileRegionVolumeComponent::ForceUnload() {
}

void UAvaTileRegionVolumeComponent::ForceLoad() {
}

void UAvaTileRegionVolumeComponent::AddTiles() {
}

UAvaTileRegionVolumeComponent::UAvaTileRegionVolumeComponent() {
    this->UnloadCO_ = false;
    this->UnloadFO_ = false;
    this->UnloadHN_ = false;
    this->UnloadHS_ = false;
    this->UnloadSW_ = false;
    this->UnloadTU_ = false;
}

