#include "Enemy_Close_QBUpdateData.h"

UEnemy_Close_QBUpdateData::UEnemy_Close_QBUpdateData() {
    this->StartDistance = 1500.00f;
    this->EndDistance = 1000.00f;
    this->bStopWhenEnding = false;
    this->bOutCanCloseIfInRange = false;
    this->Timeout = 100.00f;
}

