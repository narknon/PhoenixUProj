#include "SelfActorIsTrackedErrorReported.h"

USelfActorIsTrackedErrorReported::USelfActorIsTrackedErrorReported() {
    this->bUseName = true;
    this->bUseType = false;
    this->ErrorType = EUtilityTrackedErrorType::Error_Unspecified;
}

