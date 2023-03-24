#include "DisillusionmentSpellTool.h"

class AActor;
class UObject;



bool ADisillusionmentSpellTool::DeactivateDisillusionment(EStandardManagedPriority Priority, UObject* InInstigator) {
    return false;
}

void ADisillusionmentSpellTool::CasterHealthZero(AActor* InActor) {
}

bool ADisillusionmentSpellTool::ActivateDisillusionment(EStandardManagedPriority Priority, UObject* InInstigator) {
    return false;
}

ADisillusionmentSpellTool::ADisillusionmentSpellTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisillusionmentMat = NULL;
    this->bSlowWalk = true;
    this->Level = 0;
}

