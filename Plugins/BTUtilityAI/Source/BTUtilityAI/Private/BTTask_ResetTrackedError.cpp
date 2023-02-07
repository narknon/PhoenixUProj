#include "BTTask_ResetTrackedError.h"

UBTTask_ResetTrackedError::UBTTask_ResetTrackedError() {
    this->bUseName = true;
    this->bUseAccessory = false;
    this->bUseType = false;
    this->ErrorType = EUtilityTrackedErrorType::Error_Unspecified;
}

