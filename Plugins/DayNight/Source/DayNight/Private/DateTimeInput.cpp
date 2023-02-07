#include "DateTimeInput.h"

FDateTimeInput::FDateTimeInput() {
    this->Month = EDateTimeMonth::January;
    this->Day = 0;
    this->Year = 0;
    this->Hour = 0;
    this->AmPm = EHourAmPm::AM;
    this->Minute = 0;
}

