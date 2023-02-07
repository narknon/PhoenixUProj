#include "DayNightTemperatureCurveLightControllerComponent.h"

UDayNightTemperatureCurveLightControllerComponent::UDayNightTemperatureCurveLightControllerComponent() {
    this->Desaturation = 0.00f;
    this->bUseDirectionalBoost = false;
    this->ColorOp = EDayNightLightControllerOp::ModulateLightValue;
    this->IntensityOp = EDayNightLightControllerOp::ModulateLightValue;
    this->bAccurateColorTemp = true;
}

