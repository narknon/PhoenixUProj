#include "SpotLightWithCullingSettings.h"
#include "SpotLightComponentWithCullingSettings.h"

void ASpotLightWithCullingSettings::Copy() {
}

ASpotLightWithCullingSettings::ASpotLightWithCullingSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpotLightComponent = CreateDefaultSubobject<USpotLightComponentWithCullingSettings>(TEXT("LightComponent0"));
}

