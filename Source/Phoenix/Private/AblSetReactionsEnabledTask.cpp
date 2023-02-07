#include "AblSetReactionsEnabledTask.h"

UAblSetReactionsEnabledTask::UAblSetReactionsEnabledTask() {
    this->bReactionsEnabled = false;
    this->Priority = EStandardManagedPriority::Lowest;
}

