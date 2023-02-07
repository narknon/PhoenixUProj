#include "InventoryAbilityManager.h"

class AActor;

void UInventoryAbilityManager::SetPolyJuiceCharacter(FName PolyJuiceCharacterName) {
}

void UInventoryAbilityManager::OnGameToBeSaved() {
}

void UInventoryAbilityManager::OnGameToBeLoaded() {
}

FName UInventoryAbilityManager::GetPolyJuiceCharacter() {
    return NAME_None;
}

float UInventoryAbilityManager::GetItemeffectivenessMultiplier(AActor* OwnerActor, FName ItemName) {
    return 0.0f;
}

float UInventoryAbilityManager::GetCurrentEffectivenessMultiplier() {
    return 0.0f;
}

void UInventoryAbilityManager::AddWellRestedToPlayer() {
}

void UInventoryAbilityManager::AddWellFedToPlayer() {
}

void UInventoryAbilityManager::AddSocialNotorietyToPlayer() {
}

void UInventoryAbilityManager::AddSocialInfamousToPlayer() {
}

void UInventoryAbilityManager::AddPermenantWellRestedToPlayer() {
}

void UInventoryAbilityManager::AddPermenantWellFedToPlayer() {
}

void UInventoryAbilityManager::AddOrRefreshAbility(AActor* OwnerActor, FName ItemName, FName Name) {
}

void UInventoryAbilityManager::AddHouseLeaderToPlayer() {
}

UInventoryAbilityManager::UInventoryAbilityManager() {
    this->CurrentEffectiveness = 1.00f;
}

