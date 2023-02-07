#include "StarCatalogEntryConvert.h"

FStarCatalogEntryConvert::FStarCatalogEntryConvert() {
    this->Ordering = EStarCatalogOrdering::XYZ;
    this->PostZRotationAngleDegrees = 0.00f;
    this->bNormalizeRotation = false;
    this->NormalizeRotationAngleDegrees = 0.00f;
    this->bValidNormalizeRotation = false;
}

