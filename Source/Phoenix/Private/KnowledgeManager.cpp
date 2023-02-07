#include "KnowledgeManager.h"

class AActor;
class UKnowledgeManager;

void UKnowledgeManager::UpdateGoldChestChallenge(AActor* Chest) {
}

void UKnowledgeManager::OnSaveGameLoaded() {
}

void UKnowledgeManager::OnNewGame() {
}

void UKnowledgeManager::KnowledgeLevelSet(const FString& KnowledgeCard, const FString& Level) {
}

bool UKnowledgeManager::IsSubjectCompletelyKnown(FName ObjectID) {
    return false;
}

FName UKnowledgeManager::IsKnowledgeSubject(FName ObjectID, bool IsRecursion) {
    return NAME_None;
}

FName UKnowledgeManager::IsGroupMember(FName ObjectID) {
    return NAME_None;
}

bool UKnowledgeManager::IsFactKnown(FName ObjectID, FName FactColumnID, EKnowledgeLevel& KnowledgeLevel) {
    return false;
}

float UKnowledgeManager::GetSubjectKnowledgePoints(FName ObjectID) {
    return 0.0f;
}

FName UKnowledgeManager::GetSubjectKnowledgeCategory(FName ObjectID) {
    return NAME_None;
}

FName UKnowledgeManager::GetRegionKnowledgeCardFromLocation(FVector Location) {
    return NAME_None;
}

EKnowledgeLevel UKnowledgeManager::GetPlayerKnowledgeLevel(FName ObjectID, FName FactColumnID) {
    return EKnowledgeLevel::Unknown;
}

FName UKnowledgeManager::GetNameFromKnowledgeLevel(EKnowledgeLevel KnowledgeLevel) {
    return NAME_None;
}

TArray<FKnowledgeAuthority> UKnowledgeManager::GetKnowledgeAuthority(FName KnowledgeSubjectID) {
    return TArray<FKnowledgeAuthority>();
}

TArray<FName> UKnowledgeManager::GetGroupMembers(FName ObjectID) {
    return TArray<FName>();
}

float UKnowledgeManager::GetFieldGuideCompletionPercentage() {
    return 0.0f;
}

int32 UKnowledgeManager::GetCompanionLevel(const FString& CharacterID) {
    return 0;
}

TMap<FName, FCollectionCategory> UKnowledgeManager::GetCollections() {
    return TMap<FName, FCollectionCategory>();
}

TArray<FName> UKnowledgeManager::GetAllKnowledgeCardsByCategory(const FString& Category) {
    return TArray<FName>();
}

TArray<FName> UKnowledgeManager::GetAllKnowledgeCards() {
    return TArray<FName>();
}

UKnowledgeManager* UKnowledgeManager::Get() {
    return NULL;
}

void UKnowledgeManager::GainKnowledgeFromNPC(FName ObjectID, FName NPCID, const bool InDisplayTicker) {
}

void UKnowledgeManager::GainKnowledgeFromAction(FName ObjectID, TEnumAsByte<EKnowledgeAction> KnowledgeAction, const bool InDisplayTicker) {
}

void UKnowledgeManager::GainKnowledgeFact(FName ObjectID, FName FactColumnID, TEnumAsByte<EKnowledgeAction> KnowledgeAction, const bool InDisplayTicker) {
}

void UKnowledgeManager::CompleteAllKnowledgeCards() {
}

void UKnowledgeManager::CompleteAllCollections() {
}

void UKnowledgeManager::AddKnowledgePointsToCard(const FString& KnowledgeCard, float PointsToAdd) {
}

void UKnowledgeManager::AddKnowledgeFromInventory(const FString& Level) {
}

UKnowledgeManager::UKnowledgeManager() {
}

