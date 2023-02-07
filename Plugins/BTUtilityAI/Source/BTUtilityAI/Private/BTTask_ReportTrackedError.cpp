#include "BTTask_ReportTrackedError.h"

UBTTask_ReportTrackedError::UBTTask_ReportTrackedError() {
    this->bUseCurrentActionAsError = true;
    this->ErrorType = EUtilityTrackedErrorType::Error_Unspecified;
    this->bWaitForReset = true;
    this->MinTimeout = 5.00f;
    this->bUseRangeTimeout = false;
    this->MaxTimeout = 5.00f;
    this->ReturnType = EBTNodeResult::Succeeded;
}

