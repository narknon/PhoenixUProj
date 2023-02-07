#include "VolumetricCloudsBasicParametersOverride.h"

FVolumetricCloudsBasicParametersOverride::FVolumetricCloudsBasicParametersOverride() {
    this->bOverride_Ambient = false;
    this->bOverride_Light = false;
    this->bOverride_Extinction = false;
    this->bOverride_PowderExtinction = false;
    this->bOverride_PowderStrength = false;
    this->bOverride_FinalOutput = false;
    this->Ambient = 0.00f;
    this->Light = 0.00f;
    this->PowderExtinction = 0.00f;
    this->FinalOutput = 0.00f;
}

