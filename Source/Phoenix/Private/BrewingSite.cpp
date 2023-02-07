#include "BrewingSite.h"

class UBrewingSiteState;
class UChildActorComponent;
class USkeletalMesh;

void ABrewingSite::SetBrewingNeighborsFromChildComponents(const TArray<UChildActorComponent*>& ChildComponents, bool bLoopNeighbors) {
}


USkeletalMesh* ABrewingSite::GetCauldronSkeletalMesh_Implementation() const {
    return NULL;
}

FName ABrewingSite::GetCauldronID_Implementation() const {
    return NAME_None;
}

UBrewingSiteState* ABrewingSite::GetBrewingSiteState() {
    return NULL;
}

void ABrewingSite::DestroyPotion(FName CollectorID) {
}

void ABrewingSite::CollectPotion(FName CollectorID, bool& bOutCollectedAnything, int32& OutYieldLeft) {
}


void ABrewingSite::BeginBrewingPotion(const FBrewingRecipe& BrewingRecipe) {
}

ABrewingSite::ABrewingSite() {
    this->LeftNeighbor = NULL;
    this->RightNeighbor = NULL;
}

