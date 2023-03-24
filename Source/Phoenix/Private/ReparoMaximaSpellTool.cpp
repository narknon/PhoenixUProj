#include "ReparoMaximaSpellTool.h"

class UActorComponent;

void AReparoMaximaSpellTool::ARepairComplete(UActorComponent* Comp) {
}

AReparoMaximaSpellTool::AReparoMaximaSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FailSafeTime = 10.00f;
}

