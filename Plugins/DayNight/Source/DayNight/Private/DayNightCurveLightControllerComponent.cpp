#include "DayNightCurveLightControllerComponent.h"

UDayNightCurveLightControllerComponent::UDayNightCurveLightControllerComponent() {
    this->Desaturation = 0.00f;
    this->bUseDirectionalBoost = false;
    this->ColorOp = EDayNightLightControllerOp::ModulateLightValue;
    this->IntensityOp = EDayNightLightControllerOp::ModulateLightValue;
}

