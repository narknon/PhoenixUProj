#include "CurveClip.h"

FVector UCurveClip::GetVelocity(float InTime) const {
    return FVector{};
}

EFootPlantEnum UCurveClip::GetFootPlants(float InTime) const {
    return EFootPlantEnum::FOOTPLANT_NONE;
}

FVector UCurveClip::GetAcceleration(float InTime) const {
    return FVector{};
}

UCurveClip::UCurveClip() {
}

