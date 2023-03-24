#include "RectLightWithCullingSettings.h"
#include "RectLightComponentWithCullingSettings.h"

void ARectLightWithCullingSettings::Copy() {
}

ARectLightWithCullingSettings::ARectLightWithCullingSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RectLightComponent = CreateDefaultSubobject<URectLightComponentWithCullingSettings>(TEXT("LightComponent0"));
}

