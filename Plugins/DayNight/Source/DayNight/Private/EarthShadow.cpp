#include "EarthShadow.h"

FEarthShadow::FEarthShadow() {
    this->MeshComponent = NULL;
    this->Mesh = NULL;
    this->ZOffsetMeters = 0.00f;
    this->ScaleXY = 0.00f;
    this->bZOffsetRelativeToWorldMinZ = false;
}

