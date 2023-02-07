#include "TargetedByMunition.h"

FTargetedByMunition::FTargetedByMunition() {
    this->InstigatorPtr = NULL;
    this->TimeToReachDest = 0.00f;
    this->MunitionPtr = NULL;
    this->Deflection = false;
    this->bPerfect = false;
}

