#include "WeatherLocalWindVolume.h"

void ADEPRECATED_WeatherLocalWindVolume::SetPriority(float NewPriority) {
}

ADEPRECATED_WeatherLocalWindVolume::ADEPRECATED_WeatherLocalWindVolume() {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = false;
}

