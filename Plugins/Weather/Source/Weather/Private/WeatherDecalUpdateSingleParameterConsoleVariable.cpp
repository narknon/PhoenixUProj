#include "WeatherDecalUpdateSingleParameterConsoleVariable.h"

UWeatherDecalUpdateSingleParameterConsoleVariable::UWeatherDecalUpdateSingleParameterConsoleVariable() {
    this->MinValue = 0.00f;
    this->MaxValue = 1.00f;
    this->DefaultValue = 0.00f;
    this->bCreateIfNotFound = false;
    this->bEditorOnly = false;
    this->bUseMin = false;
    this->bUseMax = false;
}

