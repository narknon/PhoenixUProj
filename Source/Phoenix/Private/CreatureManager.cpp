#include "CreatureManager.h"
#include "CreatureScalabilityManager.h"

class AActor;
class ABiped_Player;
class ACreaturePen;
class UCreatureDefinition;
class UCreatureManager;
class UCreatureState;
class ULevel;
class UObject;
class UWorld;

void UCreatureManager::UpdateCreatureName(UCreatureState* CreatureState, const FString& Name) {
}

void UCreatureManager::UnlockAllCreatureToys() {
}

void UCreatureManager::TeleportCreatureActorsToPen(ACreaturePen* PenActor) {
}

bool UCreatureManager::SummonCreature(UCreatureState* InCreatureState, const ABiped_Player* InSummoningPlayer, FString& OutErrorKey) {
    return false;
}

AActor* UCreatureManager::SpawnShell(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel) {
    return NULL;
}

AActor* UCreatureManager::Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer) {
    return NULL;
}

TArray<UCreatureState*> UCreatureManager::SortCreaturesByHappiness(TArray<UCreatureState*> Creatures) {
    return TArray<UCreatureState*>();
}

void UCreatureManager::SetCreatureInspectedByPlayerUID(const int32 InCreatureUID) {
}

void UCreatureManager::ScrapCreature(const int32 InCreatureUID) {
}

void UCreatureManager::SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) {
}

void UCreatureManager::SaveCreatureUID(const FString& InSaveID, int32 InUIDToSave) {
}

void UCreatureManager::RestoreData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID) {
}

void UCreatureManager::RemoveSavedCreature(const FString& InSaveID) {
}

void UCreatureManager::RemoveCreatureFromInventory(const int32 InCreatureUID, bool bInRemovedByMission, bool bInSuppressHUDNotification) {
}

void UCreatureManager::ReleaseCreatureToNurturingSpace(const int32 InCreatureUID, const FName InNurturingSpaceID, const ABiped_Player* InReleasingPlayer) {
}

UCreatureState* UCreatureManager::RegisterCapturedCreature(const FName InTypeID, const bool bInIsMale, const FName InColorVariation) {
    return NULL;
}

void UCreatureManager::OnSaveGameLoaded() {
}

void UCreatureManager::OnNewGame() {
}

void UCreatureManager::OnGameToBeSaved() {
}

void UCreatureManager::OnCreatureInteractedWith(AActor* InCreature, const ECreatureInteraction InInteractionType, const FName InKnowledgeGainedActor, const FName InActorInteractedWithTypeID) {
}

bool UCreatureManager::IsPenOccupied(const int32 PenUID) const {
    return false;
}

bool UCreatureManager::IsCreatureInInventory(const int32 InCreatureUID) const {
    return false;
}

bool UCreatureManager::HasCapturedCreatureInventoryEnoughSpace() {
    return false;
}

bool UCreatureManager::GetShellSpawnPath(const FString& InItemID, FSoftObjectPath& OutPath) {
    return false;
}

UCreatureState* UCreatureManager::GetSavedCreature(const FString& InSaveID) {
    return NULL;
}

int32 UCreatureManager::GetRandomCreatureUIDFromInventory(const FName InCreatureTypeID) const {
    return 0;
}

UCreatureState* UCreatureManager::GetOffspringCreatureInPen(const int32 PenUID) const {
    return NULL;
}

int32 UCreatureManager::GetNumberOfBreedableCreaturesOfTypeInNurtureSpace(FName TypeID, FName NurturingSpaceID, bool bIncludeMale, bool bIncludeFemale) const {
    return 0;
}

UCreatureState* UCreatureManager::GetMotherCreatureInPen(const int32 PenUID) const {
    return NULL;
}

int32 UCreatureManager::GetMaxNumSpeciesInNurturingSpace(const FName InNurturingSpaceID) const {
    return 0;
}

int32 UCreatureManager::GetMaxNumCreaturesInNurturingSpace(const FName InNurturingSpaceID) const {
    return 0;
}

int32 UCreatureManager::GetMaxCreatureTierInNurturingSpace(const FName InNurturingSpaceID) const {
    return 0;
}

float UCreatureManager::GetHealth(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID) {
    return 0.0f;
}

TArray<UCreatureState*> UCreatureManager::GetHappyCreaturesInSanctuary() const {
    return TArray<UCreatureState*>();
}

float UCreatureManager::GetDeathTimeoutPercentage(const FString& InCreatureID) const {
    return 0.0f;
}

FName UCreatureManager::GetCurrentCreatureNurturingSpaceID() const {
    return NAME_None;
}

int32 UCreatureManager::GetCreatureUIDFromVariationName(const FName InUIDName) {
    return 0;
}

int32 UCreatureManager::GetCreatureInspectedByPlayerUID() const {
    return 0;
}

int32 UCreatureManager::GetCreatureEconomyValue(FName InCreatureUID) const {
    return 0;
}

TArray<UCreatureState*> UCreatureManager::GetCapturedCreatureStatesOfType(const FName InAdultTypeID) const {
    return TArray<UCreatureState*>();
}

TArray<int32> UCreatureManager::GetCapturedCreaturesOfType(const FName InTypeID) const {
    return TArray<int32>();
}

int32 UCreatureManager::GetCapturedCreatureInventorySize() const {
    return 0;
}

float UCreatureManager::GetByproductProductionTimeModifier() const {
    return 0.0f;
}

TMap<FName, int32> UCreatureManager::GetAllCreatureSpeciesInNurturingSpace(const FName InNurturingSpaceID) const {
    return TMap<FName, int32>();
}

TArray<UCreatureState*> UCreatureManager::GetAllCreaturesInNurturingSpace(const FName InNurturingSpaceID, bool bIncludeUnbornCreatures, bool bIncludeEggs, bool bSortByTimeInNurturingSpace) const {
    return TArray<UCreatureState*>();
}

TArray<UCreatureDefinition*> UCreatureManager::GetAllCreatureDefinitions() const {
    return TArray<UCreatureDefinition*>();
}

void UCreatureManager::GetAllCreatureByproducts(int32 AmountToGrant) {
}

TArray<FName> UCreatureManager::GetAllColorVariationsForCreature(const FName InTypeID) const {
    return TArray<FName>();
}

UCreatureManager* UCreatureManager::Get() {
    return NULL;
}

AActor* UCreatureManager::FindCreatureActorByUID(const int32 InCreatureUID) const {
    return NULL;
}

void UCreatureManager::CreatureStateBackup() {
}

void UCreatureManager::CreatureSpawnWildMany(FName TypeID, int32 Count) {
}

void UCreatureManager::CreatureSpawnWild(FName TypeID) {
}

void UCreatureManager::CreatureSpawnMany(FName TypeID, int32 Count) {
}

void UCreatureManager::CreatureSpawn(FName TypeID) {
}

void UCreatureManager::CreatureSimulateCapturePregnant(FName TypeID) {
}

void UCreatureManager::CreatureSimulateCapture(FName TypeID, bool bIsMale, FName ColorVariation) {
}

void UCreatureManager::CreatureSimulateBreeding(FName TypeID) {
}

void UCreatureManager::CreatureResetAllNeeds() {
}

void UCreatureManager::CreatureRemoveAll() {
}

void UCreatureManager::CreatureRegisterAllCreaturesInLevel() {
}

void UCreatureManager::CreaturePetNearest() {
}

void UCreatureManager::CreatureMeetAllNeeds() {
}

void UCreatureManager::CreatureFeedNearest() {
}

void UCreatureManager::CreatureClearCapturedInventory() {
}

void UCreatureManager::CreatureAdvancedSpawn(FName TypeID, bool bIsMale, FName ColorVariation, float ScaleVariation, const FString& CreatureName, int32 BreedingGeneration) {
}

void UCreatureManager::CreatureAddToBiomeIfNeeded(FName InCreatureType, FName InBiomeID) {
}

void UCreatureManager::CreatureAddNamedToInventory(FName NamedCreatureID) {
}

void UCreatureManager::CreatureAddHappinessToAll(float Amount) {
}

void UCreatureManager::CaptureCreature(const int32 InCreatureUID) {
}

bool UCreatureManager::CanReleaseCreatureToNurturingSpace(UCreatureState* InCreatureState, const FName InNurturingSpaceID, const ABiped_Player* InReleasingPlayer, FString& OutErrorKey) const {
    return false;
}

bool UCreatureManager::CanCreaturePairBreed(const int32 InCreatureA, const int32 InCreatureB, FString& CreatureAErrorMsg, FString& CreatureBErrorMsg) const {
    return false;
}

void UCreatureManager::BreedCreatures(UCreatureState* MotherState, UCreatureState* FatherState, ACreaturePen* CreaturePen) {
}

void UCreatureManager::BP_ScrapCreatureByFName(const FName InCreatureUID) {
}

UCreatureState* UCreatureManager::BP_GetCreatureStateByUID(const int32 InCreatureUID) const {
    return NULL;
}

UCreatureState* UCreatureManager::BP_GetCreatureStateByFName(const FName InCreatureUID) const {
    return NULL;
}

UCreatureState* UCreatureManager::BP_GetCreatureStateByActor(AActor* InCreature) const {
    return NULL;
}

UCreatureDefinition* UCreatureManager::BP_GetCreatureDefinitionForActor(AActor* InCreature) const {
    return NULL;
}

UCreatureDefinition* UCreatureManager::BP_GetCreatureDefinitionByType(const FName InTypeID) const {
    return NULL;
}

void UCreatureManager::BeginCreatureGrowUp(AActor* InCreature) {
}

ESpawnAllowedResponse UCreatureManager::AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent) {
    return ESpawnAllowedResponse::SAR_ALLOWSPAWN;
}

UCreatureManager::UCreatureManager() {
    this->CreatureScalabilityManager = CreateDefaultSubobject<UCreatureScalabilityManager>(TEXT("CreatureScalabilityManager"));
}

