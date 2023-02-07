#include "VegetationInteractionComponentDualMode.h"

void UVegetationInteractionComponentDualMode::SetVegetationInteractionModeSmooth(float TargetZeroOrOne, float RatePerSecond) {
}

void UVegetationInteractionComponentDualMode::SetVegetationInteractionModeImmediate(float TargetZeroOrOne) {
}

UVegetationInteractionComponentDualMode::UVegetationInteractionComponentDualMode() {
    this->Priority = 20.00f;
    this->Mode = 0.00f;
    this->ModeTarget = 0.00f;
    this->ModeRate = 1.00f;
}

