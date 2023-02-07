#include "TimeSourceCSVDump.h"

UTimeSourceCSVDump::UTimeSourceCSVDump() {
    this->bEnabled = false;
    this->DurationHours = 24.00f;
    this->IntervalMinutes = 5.00f;
    this->Rate = 200.00f;
    this->bCapture = false;
}

