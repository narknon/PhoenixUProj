#include "MastermindCommandResult.h"

FMastermindCommandResult::FMastermindCommandResult() {
    this->bIsSuccess = false;
    this->TestSuccess = ETestSuccess::Default;
    this->Data = NULL;
}

