#include "TransfigurationManager.h"
#include "FoliageRemoverContainer.h"
#include "PhysicalResponseReporter.h"
#include "TransformAllLoadController.h"
#include "VanishmentQueue.h"

class AActor;
class UDeferredChildActorComponent;
class ULevel;
class UObject;
class UWorld;

void UTransfigurationManager::VanishObject(AActor* InActor, bool bShowEffect, bool bReturnResources, bool bReturnAllRequiredResources, UClass* InPreviewActorClass, bool bDeferNotification) {
}

void UTransfigurationManager::UnlockTransfigurationItemsForCurriculum(TMap<EDisciplineType, int32> CurriculumYearsCompleted, bool bIncludePurchasableLocks, bool bIncludeMissionRewardLocks) {
}

void UTransfigurationManager::SpawnAllColorChangeItemsBlueprint() {
}

AActor* UTransfigurationManager::Spawn(UWorld* InWorld, const FTransform& InSpawnTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool bInIsPersistent, ESpawnActorCollisionHandlingMethod InCollisionMethod, ULevel* InOverrideLevel, UObject* InParentContainer) {
    return NULL;
}

void UTransfigurationManager::SetPowerpointSnappingEnabledBlueprint(bool bIsEnabled) {
}

void UTransfigurationManager::SetMoveablePlaceholderObjectsEnabled(bool bEnabled) {
}

void UTransfigurationManager::SetConjurationContextBlueprint(const EConjurationContext InContext) {
}

void UTransfigurationManager::ResetTransfigurationObjectTransform(AActor* InActor) {
}

void UTransfigurationManager::OnSaveGameLoaded() {
}

void UTransfigurationManager::OnNewGame() {
}

void UTransfigurationManager::OnGameToBeSaved() {
}

void UTransfigurationManager::OnDeferredChildActorSpawned(UDeferredChildActorComponent* InChildActorComponent) {
}

bool UTransfigurationManager::IsVanishmentQueueEmpty() {
    return false;
}

bool UTransfigurationManager::IsTransformAllQueueEmpty() {
    return false;
}

bool UTransfigurationManager::IsSpawnQueueEmpty() {
    return false;
}

bool UTransfigurationManager::HasTransfigSlotAvailableToConjureFromObjectCategory(const FName CategoryName, const EConjurationContext Context) {
    return false;
}

bool UTransfigurationManager::HasEnoughConjurationBudgetToConjure(const AActor* InActor) {
    return false;
}

FTransfigurationUnlockSource UTransfigurationManager::GetUnlockSourceForLockID_static(const FName LockId) {
    return FTransfigurationUnlockSource{};
}

TArray<FName> UTransfigurationManager::GetTransformationObjectList(const FName& CategoryName) {
    return TArray<FName>();
}

TArray<FName> UTransfigurationManager::GetTransformationGroups(const FName& ObjectName) {
    return TArray<FName>();
}

FName UTransfigurationManager::GetTransformationGroupForObject(const FName ObjectName) {
    return NAME_None;
}

FName UTransfigurationManager::GetTransformationCategory(const FName& ObjectName) {
    return NAME_None;
}

void UTransfigurationManager::GetTransfigurationItemsFromLockID(const FName LockId, TArray<FName>& ItemNames, TArray<FName>& ItemCategories) {
}

void UTransfigurationManager::GetTransfigurationItemFromLockID(const FName LockId, bool& bUniqueItemFound, FName& ItemName, FName& ItemCategory) {
}

FTransfigSlotPool UTransfigurationManager::GetTransfigSlotPoolFromObjectCategory(const FName CategoryName, bool& bOutPoolExists) {
    return FTransfigSlotPool{};
}

FTransfigSlotPool UTransfigurationManager::GetTransfigSlotPoolFromClassName(const FName ObjectClass, bool& bOutPoolExists) {
    return FTransfigSlotPool{};
}

FName UTransfigurationManager::GetObjectTransfigSlotIDFromActor(const AActor* InActor) {
    return NAME_None;
}

int32 UTransfigurationManager::GetObjectCostConjurationBudgetFromActor(const AActor* InActor) {
    return 0;
}

int32 UTransfigurationManager::GetObjectCostConjurationBudget(const FName CategoryName) {
    return 0;
}

void UTransfigurationManager::GetNumExpansions(const EConjurationContext InContext, int32& OutNumAvailableExpansions, int32& OutNumTotalExpansions) {
}

FName UTransfigurationManager::GetLockIDForObject(const FName inObjectName) {
    return NAME_None;
}

int32 UTransfigurationManager::GetLevelConjurationBudget(const EConjurationContext Context) {
    return 0;
}

EConjurationContext UTransfigurationManager::GetConjurationContext() {
    return EConjurationContext::None;
}

TArray<FName> UTransfigurationManager::GetConjurationCategoriesFromStatsCategory(const FName InStatsCategory, bool bIgnoreEmptyCategories) {
    return TArray<FName>();
}

void UTransfigurationManager::GetConjurationBudgetPerExpansion(const EConjurationContext InContext, float& OutMainExpansionBudget, float& OutBudgetPerUnlockableExpansion) {
}

int32 UTransfigurationManager::GetConjurationBudgetCurrentlyUsed(const EConjurationContext Context) {
    return 0;
}

TArray<FName> UTransfigurationManager::GetAllTransfigurationLocks(bool bIncludeAlreadyUnlocked) {
    return TArray<FName>();
}

TArray<FName> UTransfigurationManager::GetAllTransfigurationCategories() {
    return TArray<FName>();
}

bool UTransfigurationManager::DoesTransfigurationObjectExist(int32 ObjectUID) {
    return false;
}

void UTransfigurationManager::ColorObject(AActor* InActor, const FName InColorID, bool bShowEffect) {
}

bool UTransfigurationManager::BP_IsColovariaCacheRequiredQueueEmpty() {
    return false;
}

TArray<FTransfigurationResource> UTransfigurationManager::BP_GetResourcesRequiredForCategory(const FName CategoryName) {
    return TArray<FTransfigurationResource>();
}

TArray<FTransfigurationResource> UTransfigurationManager::BP_GetResourcesRequired(const FName TypeID) {
    return TArray<FTransfigurationResource>();
}

ESpawnAllowedResponse UTransfigurationManager::AllowSpawn(const FString& InItemID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent) {
    return ESpawnAllowedResponse::SAR_ALLOWSPAWN;
}

UTransfigurationManager::UTransfigurationManager() {
    this->VanishmentQueue = CreateDefaultSubobject<UVanishmentQueue>(TEXT("VanishmentQueue"));
    this->PhysicalResponseReporter = CreateDefaultSubobject<UPhysicalResponseReporter>(TEXT("PhysicalResponseReporter"));
    this->TransformAllController = CreateDefaultSubobject<UTransformAllLoadController>(TEXT("TransformAllController"));
    this->FoliageRemoverContainer = CreateDefaultSubobject<UFoliageRemoverContainer>(TEXT("FoliageRemoverContainer"));
}

