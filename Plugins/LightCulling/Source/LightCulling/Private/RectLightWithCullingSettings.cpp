#include "RectLightWithCullingSettings.h"
#include "RectLightComponentWithCullingSettings.h"

void ARectLightWithCullingSettings::Copy() {
}

ARectLightWithCullingSettings::ARectLightWithCullingSettings() {
    this->RectLightComponent = CreateDefaultSubobject<URectLightComponentWithCullingSettings>(TEXT("LightComponent0"));
}

