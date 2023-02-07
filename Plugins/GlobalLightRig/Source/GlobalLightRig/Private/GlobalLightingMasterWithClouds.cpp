#include "GlobalLightingMasterWithClouds.h"
#include "VolumetricCloudsComponent.h"

AGlobalLightingMasterWithClouds::AGlobalLightingMasterWithClouds() {
    this->RelativeHeightMeters = 350.00f;
    this->VisibilityBlendDomainThreshold = 0.50f;
    this->VolumetricCloudsComponent = CreateDefaultSubobject<UVolumetricCloudsComponent>(TEXT("InternalVolumetricClouds"));
}

