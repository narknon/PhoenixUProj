#include "HerbPlotManager.h"

class AActor;
class AHerbPlot;
class UHerbPlotManager;
class ULevel;
class UObject;
class UWorld;

AActor* UHerbPlotManager::SpawnShell(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel) {
    return NULL;
}

AActor* UHerbPlotManager::Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer) {
    return NULL;
}

void UHerbPlotManager::SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) {
}

void UHerbPlotManager::ResetHarvestPlantCounts() {
}

void UHerbPlotManager::OnSaveGameLoaded() {
}

void UHerbPlotManager::OnNewGame() {
}

void UHerbPlotManager::OnGameToBeSaved() {
}

void UHerbPlotManager::GetOwnedSeeds(TArray<FSeedInfo>& OwnedSeeds) {
}

float UHerbPlotManager::GetGrowthTimeMultiplier() const {
    return 0.0f;
}

FFertilizerEffect UHerbPlotManager::GetFertilizerEffectStatic(FName FertilizerID) {
    return FFertilizerEffect{};
}

TArray<FName> UHerbPlotManager::GetAllPlantNames() {
    return TArray<FName>();
}

void UHerbPlotManager::GetAllHerbologySeeds() {
}

void UHerbPlotManager::GetAllHerbologyByproducts(int32 AmountToGrant) {
}

bool UHerbPlotManager::DoesSeedFitInPlot(const FSeedInfo& SeedInfo, AHerbPlot* HerbPlot) {
    return false;
}

FPlantDefinition UHerbPlotManager::BP_GetPlantDefinition(FName PlantID, bool& DefinitionFound) {
    return FPlantDefinition{};
}

UHerbPlotManager* UHerbPlotManager::BP_Get() {
    return NULL;
}

ESpawnAllowedResponse UHerbPlotManager::AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent) {
    return ESpawnAllowedResponse::SAR_ALLOWSPAWN;
}

UHerbPlotManager::UHerbPlotManager() {
}

