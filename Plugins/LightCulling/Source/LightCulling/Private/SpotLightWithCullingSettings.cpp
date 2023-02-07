#include "SpotLightWithCullingSettings.h"
#include "SpotLightComponentWithCullingSettings.h"

void ASpotLightWithCullingSettings::Copy() {
}

ASpotLightWithCullingSettings::ASpotLightWithCullingSettings() {
    this->SpotLightComponent = CreateDefaultSubobject<USpotLightComponentWithCullingSettings>(TEXT("LightComponent0"));
}

