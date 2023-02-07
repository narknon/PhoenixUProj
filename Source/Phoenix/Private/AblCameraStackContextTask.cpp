#include "AblCameraStackContextTask.h"

UAblCameraStackContextTask::UAblCameraStackContextTask() {
    this->TaskStartOperation = EAblCameraStackContextOperation::AddContext;
    this->TaskEndOperation = EAblCameraStackContextOperation::RemoveContext;
}

