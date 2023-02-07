#include "ScheduleEntry.h"

FScheduleEntry::FScheduleEntry() {
    this->StartTime = 0;
    this->EndTime = 0;
    this->DaysMask = 0;
    this->flags = 0;
    this->StartTimeInMinutes = 0;
    this->EndTimeInMinutes = 0;
    this->DurationMinutes = 0;
    this->PathLength = 0.00f;
    this->PathLengthAB = 0.00f;
    this->MoveSpeed = 0.00f;
    this->TimeAvailableSeconds = 0.00f;
    this->TimeRequiredSeconds = 0.00f;
    this->Priority = 0;
    this->TravelTimeFactor = 0.00f;
    this->DistanceTraveled = 0.00f;
}

