#include "SanctuaryManager.h"

class AActor;
class ASanctuaryItemGenerator;
class UObject;
class USanctuaryExpansionManager;
class USanctuaryManager;

void USanctuaryManager::SetInitialSanctuaryCustomizationChoice(const UObject* WorldContextObject, const FString& InChoice) {
}

void USanctuaryManager::SetCustomNameForChest(int32 ObjectUID, const FString& NewName) const {
}

void USanctuaryManager::RemoveCreatureToyFromBiome(const AActor* ToyActor) {
}

void USanctuaryManager::OnToyChestEndPlay(const AActor* ToyChestActor) {
}

void USanctuaryManager::OnToyChestBeginPlay(const AActor* ToyChestActor) {
}

void USanctuaryManager::OnStartNewInterval(const FTimeEvent& InTimeEvent) {
}

void USanctuaryManager::OnSaveGameLoaded() {
}

void USanctuaryManager::OnSanctuaryItemGeneratorFinished(const FTimeEvent& InTimeEvent) {
}

void USanctuaryManager::OnNewGame() {
}

FTimespan USanctuaryManager::GetSanctuaryItemGeneratorTimeRemaining(ASanctuaryItemGenerator* ItemGenerator) const {
    return FTimespan{};
}

float USanctuaryManager::GetSanctuaryItemGeneratorProgress(ASanctuaryItemGenerator* ItemGenerator) const {
    return 0.0f;
}

void USanctuaryManager::GetSanctuaryItemGeneratorItemHeld(ASanctuaryItemGenerator* ItemGenerator, FName& OutItemHeld, int32& OutQuantity) const {
}

FName USanctuaryManager::GetSanctuaryItemGeneratorGuaranteedOutputItem(ASanctuaryItemGenerator* ItemGenerator) const {
    return NAME_None;
}

TArray<FSanctuaryExpansionDefinition> USanctuaryManager::GetSanctuaryExpansions(FName AreaID) const {
    return TArray<FSanctuaryExpansionDefinition>();
}

FName USanctuaryManager::GetNurturingSpaceIDFromBiomeLevel(const FString& LevelPath) const {
    return NAME_None;
}

FName USanctuaryManager::GetNurturingSpaceIDFromBiomeID(FName BiomeID) const {
    return NAME_None;
}

void USanctuaryManager::GetNurtureSpacesContainingCreatures(bool bIncludeInventory, bool bIncludeSanctuaryBiomes, bool bIncludeOther, TSet<FName>& OutNurtureSpaceIDs) const {
}

ESanctuaryIdentity USanctuaryManager::GetInitialSanctuaryLightingIdentity() const {
    return ESanctuaryIdentity::Default;
}

USanctuaryExpansionManager* USanctuaryManager::GetExpansionManager() const {
    return NULL;
}

FString USanctuaryManager::GetCustomNameForChest(int32 ObjectUID) const {
    return TEXT("");
}

FName USanctuaryManager::GetBiomeIDFromNurturingSpaceID(FName NurturingSpaceID) const {
    return NAME_None;
}

FName USanctuaryManager::GetBiomeIDFromLevel(const FString& LevelPath) const {
    return NAME_None;
}

USanctuaryManager* USanctuaryManager::Get(bool bCreateIfNull) {
    return NULL;
}

void USanctuaryManager::AddCreatureToyToBiome(const AActor* ToyActor) {
}

USanctuaryManager::USanctuaryManager() {
    this->ExpansionManager = NULL;
}

