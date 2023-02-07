#include "WindGustControllerSimplexNoise.h"

UWindGustControllerSimplexNoise::UWindGustControllerSimplexNoise() {
    this->TimeScale = 0.10f;
    this->Mode = EWindGustSimplexNoiseMode::Simple;
    this->Seed = 0.00f;
}

