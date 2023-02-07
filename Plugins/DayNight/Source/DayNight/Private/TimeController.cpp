#include "TimeController.h"

FTimeController::FTimeController() {
    this->TimeDateSource = NULL;
    this->RateTarget = 0.00f;
    this->RateFilter = 0.00f;
}

