#include "BrewingSiteState.h"

void UBrewingSiteState::InstantlyCompleteBrewing() {
}

int32 UBrewingSiteState::GetUncollectedYield() const {
    return 0;
}

int32 UBrewingSiteState::GetRecipeYield() const {
    return 0;
}

TArray<FRecipeIngredient> UBrewingSiteState::GetRecipeIngredients() const {
    return TArray<FRecipeIngredient>();
}

FName UBrewingSiteState::GetPotionID() const {
    return NAME_None;
}

FName UBrewingSiteState::GetOutputItemID() const {
    return NAME_None;
}

bool UBrewingSiteState::GetIsInSanctuary() const {
    return false;
}

bool UBrewingSiteState::GetHasInventorySpaceToCollectPotion(FName CollectorID, int32& OutYieldLeft) const {
    return false;
}

FTimespan UBrewingSiteState::GetBrewingTimeRemaining() const {
    return FTimespan{};
}

EBrewingState UBrewingSiteState::GetBrewingState() const {
    return EBrewingState::None;
}

float UBrewingSiteState::GetBrewingProgressRatio() const {
    return 0.0f;
}

UBrewingSiteState::UBrewingSiteState() {
}

