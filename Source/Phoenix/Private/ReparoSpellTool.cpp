#include "ReparoSpellTool.h"

class UActorComponent;
class UObject;

void AReparoSpellTool::ReparoExpired() {
}

void AReparoSpellTool::ReparoCancel(const UObject* InInstigator) {
}

void AReparoSpellTool::DisableReparoAOE(bool Disable) {
}

void AReparoSpellTool::ARepairComplete(UActorComponent* Comp) {
}

AReparoSpellTool::AReparoSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bOnlyHitTarget = false;
    this->TargetQueryCapsuleRadius = 200.00f;
    this->TargetQueryCapsuleOffsetX = 0.00f;
}

