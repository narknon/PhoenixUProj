#include "EnvironmentalGlobalsLightDirection.h"

FEnvironmentalGlobalsLightDirection::FEnvironmentalGlobalsLightDirection() {
    this->AzimuthDegrees = 0.00f;
    this->AltitudeDegrees = 0.00f;
    this->UnitIntensity = 0.00f;
    this->Intensity = 0.00f;
    this->AtmosphericIntensity = 0.00f;
    this->bInferredFromWorld = false;
}

