#include "WorldEventCondition_TimeOfTheDay.h"

UWorldEventCondition_TimeOfTheDay::UWorldEventCondition_TimeOfTheDay() {
    this->StartHour = 0;
    this->StartMinute = 0;
    this->StartSeconds = 0;
    this->EndHour = 0;
    this->EndMinute = 0;
    this->EndSeconds = 0;
    this->bDespawnOnConditionFail = true;
}

