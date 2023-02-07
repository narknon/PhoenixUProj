#include "AIPerformTaskWaitForHermes.h"

class UObject;

void UAIPerformTaskWaitForHermes::OnHermesMessageExecuted(const UObject* i_caller) {
}

UAIPerformTaskWaitForHermes::UAIPerformTaskWaitForHermes() {
    this->CustomHermesMessage = TEXT("ExecuteNextPerformTaskForTrigger");
    this->bOrientToPlayer = true;
}

