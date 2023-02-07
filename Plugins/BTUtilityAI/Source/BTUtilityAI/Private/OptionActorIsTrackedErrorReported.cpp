#include "OptionActorIsTrackedErrorReported.h"

UOptionActorIsTrackedErrorReported::UOptionActorIsTrackedErrorReported() {
    this->bUseName = true;
    this->bUseType = false;
    this->ErrorType = EUtilityTrackedErrorType::Error_Unspecified;
}

