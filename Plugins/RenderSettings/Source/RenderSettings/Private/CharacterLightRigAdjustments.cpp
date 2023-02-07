#include "CharacterLightRigAdjustments.h"

FCharacterLightRigAdjustments::FCharacterLightRigAdjustments() {
    this->IntensityMod = 0.00f;
    this->TemperatureMod = 0.00f;
    this->DayNightLerp = 0.00f;
    this->bIntensityMod = false;
    this->bOverrideTemperatureMod = false;
    this->bOverrideDayNightLerp = false;
}

