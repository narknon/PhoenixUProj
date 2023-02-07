#include "TimeSourceFromDateTime.h"

void UTimeSourceFromDateTime::EditorForceUpdate() {
}

UTimeSourceFromDateTime::UTimeSourceFromDateTime() {
    this->Rate = 20.00f;
    this->bUseRate = false;
    this->bEnabled = true;
}

