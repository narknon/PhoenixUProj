#include "BTDecorator_IsTrackedErrorReported.h"

UBTDecorator_IsTrackedErrorReported::UBTDecorator_IsTrackedErrorReported() {
    this->bUseName = true;
    this->bUseAccessory = false;
    this->bUseType = false;
    this->ErrorType = EUtilityTrackedErrorType::Error_Unspecified;
}

