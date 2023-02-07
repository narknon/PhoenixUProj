#include "Enemy_TargetSense.h"

FEnemy_TargetSense::FEnemy_TargetSense() {
    this->bOverrideLOS = false;
    this->bOverrideFOV = false;
    this->bOverrideRemember = false;
    this->bOverrideTAS = false;
    this->bOverrideEvaluateDist = false;
    this->EvaluateDist = 0.00f;
    this->StealthShowBlipDist = 0.00f;
}

