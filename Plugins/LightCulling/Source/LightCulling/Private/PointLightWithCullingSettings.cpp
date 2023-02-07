#include "PointLightWithCullingSettings.h"
#include "PointLightComponentWithCullingSettings.h"

void APointLightWithCullingSettings::Copy() {
}

APointLightWithCullingSettings::APointLightWithCullingSettings() {
    this->PointLightComponent = CreateDefaultSubobject<UPointLightComponentWithCullingSettings>(TEXT("LightComponent0"));
}

