#include "VolumetricCloudsActor.h"
#include "VolumetricCloudsComponent.h"

AVolumetricCloudsActor::AVolumetricCloudsActor() {
    this->Component = CreateDefaultSubobject<UVolumetricCloudsComponent>(TEXT("VolumetricCloudsComponent0"));
    this->GroundShadowsStrength = 0.50f;
    this->bUsePresetLighting = true;
    this->bUsePresetWeatherWind = true;
}

