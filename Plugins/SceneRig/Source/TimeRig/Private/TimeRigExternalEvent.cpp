#include "TimeRigExternalEvent.h"

UTimeRigExternalEvent::UTimeRigExternalEvent() {
    this->Constraint = ETimeRigExternalEventConstraint::NotConstrained;
    this->DefaultTime = 0.00f;
}

