#include "PointLightWithCullingSettings.h"
#include "PointLightComponentWithCullingSettings.h"

void APointLightWithCullingSettings::Copy() {
}

APointLightWithCullingSettings::APointLightWithCullingSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PointLightComponent = CreateDefaultSubobject<UPointLightComponentWithCullingSettings>(TEXT("LightComponent0"));
}

