#include "DistanceFogOverrides.h"

FDistanceFogOverrides::FDistanceFogOverrides() {
    this->bOverride_OnOff = false;
    this->bOverride_FogGradientHorizonOffset = false;
    this->bOverride_MaxFogOpacityPercent = false;
    this->bOverride_StartDistance = false;
    this->bOverride_FullDistance = false;
    this->bOverride_Thickness = false;
    this->bOverride_BlendSceneColorPercent = false;
    this->OnOff = 0.00f;
    this->FogGradientHorizonOffset = 0.00f;
    this->MaxFogOpacityPercent = 0.00f;
    this->StartDistance = 0.00f;
    this->FullDistance = 0.00f;
    this->Thickness = 0.00f;
    this->BlendSceneColorPercent = 0.00f;
}

