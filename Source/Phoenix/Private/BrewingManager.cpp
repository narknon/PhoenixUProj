#include "BrewingManager.h"


void UBrewingManager::UnlockAllPotionRecipes() {
}

void UBrewingManager::OnSaveGameLoaded() {
}

void UBrewingManager::OnNewGame() {
}

void UBrewingManager::OnGameToBeSaved() {
}

float UBrewingManager::GetBrewTimeMultiplier() const {
    return 0.0f;
}

TArray<FName> UBrewingManager::GetBrewingUICategories() const {
    return TArray<FName>();
}

void UBrewingManager::GetBrewingRecipes(TArray<FBrewingRecipe>& AvailableRecipes, TArray<FBrewingRecipe>& LockedRecipes) {
}

void UBrewingManager::GetAllPotions(int32 AmountToGrant) {
}

void UBrewingManager::GetAllPotionIngredients(int32 AmountToGrant) {
}

UBrewingManager* UBrewingManager::BP_Get() {
    return NULL;
}

bool UBrewingManager::AreOwnedIngredientsEnough(const FBrewingRecipe& BrewingRecipe) {
    return false;
}

UBrewingManager::UBrewingManager() {
}

