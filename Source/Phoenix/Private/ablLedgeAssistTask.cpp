#include "ablLedgeAssistTask.h"

UablLedgeAssistTask::UablLedgeAssistTask() {
    this->DesiredRootUpOffsetM = 0.00f;
    this->DesiredRootNormalOffsetM = 0.00f;
    this->DesiredRootUpOffsetF = 0.00f;
    this->DesiredRootNormalOffsetF = 0.00f;
    this->DesiredRootUpOffsetC = 0.00f;
    this->AlignRotation = false;
    this->RotationOffset = 0.00f;
    this->AlignToMount = false;
    this->TurnOffCollisionDuringAlign = false;
}

