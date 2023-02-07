#include "TimeSourceScrubbable.h"
#include "TimeSourceScrubbableControl.h"

UTimeSourceScrubbable::UTimeSourceScrubbable() {
    this->ControlClass = UTimeSourceScrubbableControl::StaticClass();
    this->bEnabled = true;
}

