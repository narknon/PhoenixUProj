#include "Enemy_TargetSense_TAS.h"

FEnemy_TargetSense_TAS::FEnemy_TargetSense_TAS() {
    this->EventMaintainTime = 0.00f;
    this->EventAwareAlertValue = 0.00f;
    this->EnterAwareDistCurve = NULL;
    this->EnterAlertDistCurve = NULL;
    this->ExitAwareDistCurve = NULL;
    this->ExitAlertDistCurve = NULL;
}

