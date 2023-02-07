#include "BTTask_PlayAbilityBase.h"

UBTTask_PlayAbilityBase::UBTTask_PlayAbilityBase() {
    this->AbilityChannelName = TEXT("FullBody");
    this->MarkAsInProgressDuringExecution = false;
    this->bWaitForHermesMessage = false;
    this->MessageName = TEXT("AnimComplete");
}

