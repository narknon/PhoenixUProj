#include "Tool.h"

class AActor;
class UToolRecord;
class UToolSetComponent;

AActor* ATool::GetUltimateOwner() {
    return NULL;
}

UToolRecord* ATool::GetToolRecord() const {
    return NULL;
}

UToolSetComponent* ATool::GetOurToolSetComponent() const {
    return NULL;
}

void ATool::DeactivationFx_Implementation() {
}

void ATool::DeactivationComplete() {
}



void ATool::ActivateFx_Implementation() {
}

ATool::ATool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseEffectsOnTool = false;
    this->EffectsTimeIn = 0.25f;
    this->EffectsTimeOut = 0.20f;
    this->EquipSfx = NULL;
    this->UnequipSfx = NULL;
}

