#include "GroundSwarmingCurlNoiseParameters.h"

FGroundSwarmingCurlNoiseParameters::FGroundSwarmingCurlNoiseParameters() {
    this->Mode = EGroundSwarmingCurlNoiseMode::None;
    this->Scale = 0.00f;
    this->SampleRate = 0.00f;
    this->Force = 0.00f;
    this->ForceVariancePercent = 0.00f;
    this->Epsilon = 0.00f;
}

