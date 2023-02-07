#include "CurveBuildingParams.h"

FCurveBuildingParams::FCurveBuildingParams() {
    this->SamplesPerSecond = 0;
    this->MaxSamples = 0;
    this->MinValueChange = 0.00f;
    this->KeyOptimizeThreshold = 0;
    this->RedundantKeyTolerance = 0.00f;
    this->bOptimize = false;
    this->bCubic = false;
}

