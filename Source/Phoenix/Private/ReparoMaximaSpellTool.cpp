#include "ReparoMaximaSpellTool.h"

class UActorComponent;

void AReparoMaximaSpellTool::ARepairComplete(UActorComponent* Comp) {
}

AReparoMaximaSpellTool::AReparoMaximaSpellTool() {
    this->FailSafeTime = 10.00f;
}

