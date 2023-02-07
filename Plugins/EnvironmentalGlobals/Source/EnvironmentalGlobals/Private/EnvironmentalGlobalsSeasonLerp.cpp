#include "EnvironmentalGlobalsSeasonLerp.h"

FEnvironmentalGlobalsSeasonLerp::FEnvironmentalGlobalsSeasonLerp() {
    this->Season = ESeasonEnum::Season_Invalid;
    this->Phases = 0;
    this->Phase = 0;
    this->Lerp = 0.00f;
}

