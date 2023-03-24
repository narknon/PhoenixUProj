#include "Herb.h"

class AHerbPlot;

bool AHerb::TryCreateBeacon() {
    return false;
}


bool AHerb::IsMultiHarvestable() {
    return false;
}

bool AHerb::IsInPlot() const {
    return false;
}

bool AHerb::IsFinalStage(int32 Stage) const {
    return false;
}

AHerbPlot* AHerb::GetPlot() const {
    return NULL;
}

FName AHerb::GetPlantByproductID(FName PlantID) {
    return NAME_None;
}

int32 AHerb::GetNumStages_Implementation() const {
    return 0;
}

bool AHerb::GetHasInventorySpaceToHarvestPlantOfType(const FName PlantID, const FName CollectorCharacterID, const FName FertilizerID, bool bIsPlanted) {
    return false;
}

void AHerb::FinishHarvestingHerb() {
}




AHerb::AHerb(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RespawnTime = 259200;
    this->CurrentStage = 0;
}

