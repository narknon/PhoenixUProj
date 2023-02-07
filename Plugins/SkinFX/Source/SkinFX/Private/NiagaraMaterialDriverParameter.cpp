#include "NiagaraMaterialDriverParameter.h"

FNiagaraMaterialDriverParameter::FNiagaraMaterialDriverParameter() {
    this->Type = ENiagaraMaterialDriverParameterType::Scalar;
    this->Scale = 0.00f;
    this->bEnabled = false;
    this->bScale = false;
}

