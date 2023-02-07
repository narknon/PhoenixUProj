#include "BTTask_StopAbility.h"

UBTTask_StopAbility::UBTTask_StopAbility() {
    this->CancelActive = true;
    this->Ability = NULL;
    this->ResultToUse = Successful;
}

