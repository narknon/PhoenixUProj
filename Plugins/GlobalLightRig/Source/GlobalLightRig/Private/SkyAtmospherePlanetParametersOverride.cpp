#include "SkyAtmospherePlanetParametersOverride.h"

FSkyAtmospherePlanetParametersOverride::FSkyAtmospherePlanetParametersOverride() {
    this->bOverride_BottomRadius = false;
    this->bOverride_AtmosphereHeight = false;
    this->bOverride_GroundAlbedo = false;
    this->BottomRadius = 0.00f;
    this->AtmosphereHeight = 0.00f;
}

