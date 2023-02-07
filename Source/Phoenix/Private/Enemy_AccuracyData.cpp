#include "Enemy_AccuracyData.h"

FEnemy_AccuracyData::FEnemy_AccuracyData() {
    this->MissThreshold = 0.00f;
    this->MissOffset = 0.00f;
    this->NotTargettedMissAdjust = 0.00f;
    this->RunningAwayMissAdjust = 0.00f;
    this->DistFromPlayerCurve = NULL;
    this->TimeOffscreenCurve = NULL;
    this->TimeSinceAttackedCurve = NULL;
}

