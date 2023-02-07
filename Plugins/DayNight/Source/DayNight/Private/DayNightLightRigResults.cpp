#include "DayNightLightRigResults.h"

FDayNightLightRigResults::FDayNightLightRigResults() {
    this->Night0Day1 = 0.00f;
    this->SunLightInfluence = 0.00f;
    this->MoonLightInfluence = 0.00f;
    this->LightSource = EDayNightLightSource::Sun;
    this->BlendOps = 0;
    this->SunAltitudeDegrees = 0.00f;
    this->MoonAltitudeDegrees = 0.00f;
    this->NormalizedTime = 0.00f;
    this->bUsingSecondaryDirectionalLight = false;
}

