#include "WeatherSurfaceCharacterFXSettings.h"

FWeatherSurfaceCharacterFXSettings::FWeatherSurfaceCharacterFXSettings() {
    this->SkinFX = NULL;
    this->NiagaraVFX = NULL;
    this->StartSoundFX = NULL;
    this->EndSoundFX = NULL;
    this->FullCoverageMinutes = 0.00f;
    this->FullDryMinutes = 0.00f;
    this->ClampCoverage = 0.00f;
    this->LocalCoverateRateFilter = 0.00f;
    this->bSetSkinFXStormLocalCoverageParameter = false;
    this->bSetNiagaraVFXSpawnRateMultiply = false;
    this->bSetNiagaraVFXStormLocalCoverageParameter = false;
}

