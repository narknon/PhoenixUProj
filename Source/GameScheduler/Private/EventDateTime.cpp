#include "EventDateTime.h"

FEventDateTime::FEventDateTime() {
    this->Year = 0;
    this->Month = January;
    this->Day = 0;
    this->Hour = 0;
    this->Minute = 0;
    this->Second = 0;
    this->DeltaMonths = 0.00f;
    this->DeltaDays = 0.00f;
    this->DeltaHours = 0.00f;
    this->DeltaMinutes = 0.00f;
    this->DeltaSeconds = 0.00f;
    this->DaysMask = 0;
}

