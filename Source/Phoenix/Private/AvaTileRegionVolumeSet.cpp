#include "AvaTileRegionVolumeSet.h"

void AAvaTileRegionVolumeSet::ForceDeactivate() {
}

void AAvaTileRegionVolumeSet::ForceActivate() {
}

AAvaTileRegionVolumeSet::AAvaTileRegionVolumeSet() {
    this->UnloadCO_ = false;
    this->UnloadFO_ = false;
    this->UnloadHN_ = false;
    this->UnloadHS_ = false;
    this->UnloadSW_ = false;
    this->UnloadTU_ = false;
}

