#include "DynamicLightAdaptationEVValue.h"

FDynamicLightAdaptationEVValue::FDynamicLightAdaptationEVValue() {
    this->Type = EDynamicLightAdaptationEVValueType::Absolute;
    this->EVValue = 0.00f;
    this->MinMaxTarget = 0.00f;
}

