#include "DayNightLightSkyAtmosphereComputeSampleDirectionParams.h"

FDayNightLightSkyAtmosphereComputeSampleDirectionParams::FDayNightLightSkyAtmosphereComputeSampleDirectionParams() {
    this->SampleOffsetAltitudeDegrees = 0.00f;
    this->MinimumSampleAltitudeDegrees = 0.00f;
    this->MaximumSampleAltitudeDegrees = 0.00f;
    this->bMirrorLowerHemisphere = false;
    this->bUseMinimumSampleAltitudeDegrees = false;
    this->bUseMaximumSampleAltitudeDegrees = false;
}

