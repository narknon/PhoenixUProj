#include "AblNpcScaleTask.h"

UAblNpcScaleTask::UAblNpcScaleTask() {
    this->ScaleStart = 1.00f;
    this->ScaleEnd = 1.00f;
    this->bScaleToPreviousValue = true;
    this->bRestoreScaleAtTaskEnd = true;
    this->bUseCurve = false;
    this->Curve = NULL;
}

