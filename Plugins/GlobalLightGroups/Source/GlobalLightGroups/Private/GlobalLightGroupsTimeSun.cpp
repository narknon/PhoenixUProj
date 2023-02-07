#include "GlobalLightGroupsTimeSun.h"

FGlobalLightGroupsTimeSun::FGlobalLightGroupsTimeSun() {
    this->Angle = EGlobalLightGroupsSunAngle::FullBrightSky;
    this->Direction = EGlobalLightGroupsSunDirection::Rise;
    this->AngleOffset = 0.00f;
    this->VarianceMinutesMin = 0.00f;
    this->VarianceMinutesMax = 0.00f;
}

