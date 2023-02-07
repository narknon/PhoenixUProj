#include "FullWeatherState.h"

FFullWeatherState::FFullWeatherState() {
    this->Overcast = 0.00f;
    this->Cold = 0.00f;
    this->bFogFollowCamera = false;
    this->bCloudsPresetValid = false;
    this->bCloudsWindValid = false;
    this->bSunDiskOverridesValid = false;
    this->bFogValid = false;
    this->bFogNoiseOverrideValid = false;
    this->bFogNoiseOverrideHistoryValid = false;
    this->bOvercastValid = false;
    this->bColdValid = false;
    this->bPrecipitationValid = false;
    this->bStormTypeValid = false;
    this->bStormCoverageValid = false;
    this->bStormIntensityValid = false;
    this->bStormHeightValid = false;
    this->bSurfaceFogTypeValid = false;
    this->bSurfaceFogIntensityValid = false;
}

