#include "WeatherSurfaceCharacterFXState.h"

FWeatherSurfaceCharacterFXState::FWeatherSurfaceCharacterFXState() {
    this->SkinFX = NULL;
    this->NiagaraVFX = NULL;
    this->WeatherDecalsState = NULL;
    this->StartSoundFXHandle = 0;
    this->EndSoundFXHandle = 0;
    this->LocalCoverage = 0.00f;
    this->LocalCoverageRate = 0.00f;
    this->CachedIndoors = 0.00f;
    this->CachedIndoorsAgeMilliseconds = 0.00f;
    this->NextSkinFXParameterUpdate = 0.00f;
    this->SuspendedTimer = 0.00f;
    this->State = EWeatherSurfaceCharacterFXWetState::Dry;
    this->bCheckedIfSwappable = false;
    this->bSuspended = false;
    this->bAlwaysOutdoors = false;
    this->bExactInside = false;
    this->bDryingOut = false;
}

