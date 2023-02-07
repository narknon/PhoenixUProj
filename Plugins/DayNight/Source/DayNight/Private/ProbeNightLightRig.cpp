#include "ProbeNightLightRig.h"

UProbeNightLightRig::UProbeNightLightRig() {
    this->DirectionMode = EProbeNightLightMoonDirection::FromSkyState;
    this->bUseMoonSetup = true;
    this->bUseLightRig = true;
}

