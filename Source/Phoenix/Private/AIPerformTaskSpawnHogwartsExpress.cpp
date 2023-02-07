#include "AIPerformTaskSpawnHogwartsExpress.h"

UAIPerformTaskSpawnHogwartsExpress::UAIPerformTaskSpawnHogwartsExpress() {
    this->CurrentTaskSetting = EPerformTaskHogwarsExpressSettings::Activate;
    this->bUpdateLocation = false;
    this->bUpdateSpeed = false;
    this->NewSpeed = 0.00f;
}

