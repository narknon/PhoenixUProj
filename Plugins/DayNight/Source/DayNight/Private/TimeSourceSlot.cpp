#include "TimeSourceSlot.h"

void UTimeSourceSlot::EditorForceUpdate() {
}

UTimeSourceSlot::UTimeSourceSlot() {
    this->DayOfWeek = EDateTimeDayOfWeek::Saturday;
    this->Rate = 50.00f;
    this->bUseRate = false;
    this->SlotRate = 1.00f;
}

