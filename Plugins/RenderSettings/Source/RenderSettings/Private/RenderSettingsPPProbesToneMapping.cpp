#include "RenderSettingsPPProbesToneMapping.h"

FRenderSettingsPPProbesToneMapping::FRenderSettingsPPProbesToneMapping() {
    this->bOverride_ProbeToneMapAmount = false;
    this->bOverride_ProbeToneMapMinIntensity = false;
    this->bOverride_ProbeToneMapMaxEV = false;
    this->ProbeToneMapAmount = 0.00f;
    this->ProbeToneMapMinIntensity = 0.00f;
    this->ProbeToneMapMaxEV = 0.00f;
}

