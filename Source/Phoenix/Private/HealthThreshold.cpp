#include "HealthThreshold.h"

FHealthThreshold::FHealthThreshold() {
    this->HealthValue = 0.00f;
    this->bHealthValueIsPercent = false;
    this->bDamageStop = false;
    this->DamageStopTime = 0.00f;
    this->bShowInUI = false;
}

