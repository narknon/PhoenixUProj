#include "WeatherLocalWindComponent.h"

void UDEPRECATED_WeatherLocalWindComponent::SetPriority(float NewPriority) {
}

UDEPRECATED_WeatherLocalWindComponent::UDEPRECATED_WeatherLocalWindComponent() {
    this->Priority = 0.00f;
    this->BlendRadius = 100.00f;
    this->BlendWeight = 1.00f;
    this->bEnabled = true;
    this->bUnbounded = false;
}

