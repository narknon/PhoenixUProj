#include "TimeSourceScrubbableControl.h"

UTimeSourceScrubbableControl::UTimeSourceScrubbableControl() {
    this->DaysOffset = 0.00f;
    this->HoursOffset = 12.00f;
    this->MinutesOffset = 0.00f;
    this->SecondsOffset = 0;
    this->bWholeDays = true;
    this->bWholeHours = false;
    this->bWholeMinutes = false;
}

