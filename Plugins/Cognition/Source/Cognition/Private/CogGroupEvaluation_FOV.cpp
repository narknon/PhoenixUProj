#include "CogGroupEvaluation_FOV.h"

UCogGroupEvaluation_FOV::UCogGroupEvaluation_FOV() {
    this->FOV = 45.00f;
    this->bAutoAcceptIfFootprintOverlap = false;
    this->bUseTargetFootprintForFOV = true;
    this->bIgnoreForSticky = true;
}

