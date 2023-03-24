#include "HerbPlot.h"

class AHerb;
class UChildActorComponent;
class UHerbPlotState;

void AHerbPlot::SetPlotNeighborsFromChildComponents(const TArray<UChildActorComponent*>& ChildComponents, bool bLoopNeighbors) {
}

void AHerbPlot::PlantSeed(FName PlantID, FName InteractorID) {
}










bool AHerbPlot::IsInLineWithNeighbors() const {
    return false;
}

void AHerbPlot::HarvestHerb(FName CollectorCharacterID) {
}

UHerbPlotState* AHerbPlot::GetPlotState() {
    return NULL;
}

AHerb* AHerbPlot::GetPlantedHerb() const {
    return NULL;
}

void AHerbPlot::ForceState(const FName PlantID, const FName FertilizerID, const EHerbGrowthState GrowthState, const float GrowthProgress) {
}

void AHerbPlot::ForceGrowthState(const EHerbGrowthState GrowthState, const float GrowthProgress) {
}



void AHerbPlot::DestroyHerb() {
}

void AHerbPlot::ApplyFertilizer(FName FertilizerID, FName InteractorID) {
}

AHerbPlot::AHerbPlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PotionedSFXEvent = NULL;
    this->FertilizedSFXEvent = NULL;
    this->PlantedSFXEvent = NULL;
    this->LeftNeighbor = NULL;
    this->RightNeighbor = NULL;
}

