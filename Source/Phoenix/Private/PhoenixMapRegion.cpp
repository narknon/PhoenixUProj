#include "PhoenixMapRegion.h"

APhoenixMapRegion::APhoenixMapRegion(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RegionMaterialDynamic = NULL;
    this->Region = ERegionType::HogwartsRegion;
    this->SubRegion = ERegionType::HogwartsInitialRegion;
    this->SubRegionIndex = 0;
    this->IsSubRegion = false;
    this->IsLevelBounds = false;
    this->IsInnerLevelBounds = false;
    this->IsSpecialCase = false;
    this->RegionFowardAxis = ESplineMeshAxis::X;
}

