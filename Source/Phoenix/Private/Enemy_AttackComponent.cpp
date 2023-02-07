#include "Enemy_AttackComponent.h"

class UEnemyAIAttackData;

void UEnemy_AttackComponent::RemoveSelectionTags(const FGameplayTagContainer& InTags) {
}

void UEnemy_AttackComponent::RemoveSelectionTag(const FGameplayTag& InTag) {
}

bool UEnemy_AttackComponent::IsAttackAllowed(UEnemyAIAttackData* AttackPtr) const {
    return false;
}

bool UEnemy_AttackComponent::HasSelectionTag(const FGameplayTag& InTag) const {
    return false;
}

bool UEnemy_AttackComponent::HasChosenAttack() const {
    return false;
}

FEnemyAIChosenAttackData UEnemy_AttackComponent::GetChosenAttackData() {
    return FEnemyAIChosenAttackData{};
}

FEnemy_UnblockableData UEnemy_AttackComponent::GetAttackUnblockableData(UEnemyAIAttackData* attackDataPtr) const {
    return FEnemy_UnblockableData{};
}

UEnemyAIAttackData* UEnemy_AttackComponent::GetAttackData() const {
    return NULL;
}

void UEnemy_AttackComponent::ClearSelectionTags() {
}

void UEnemy_AttackComponent::AddSelectionTags(const FGameplayTagContainer& InTags) {
}

void UEnemy_AttackComponent::AddSelectionTag(const FGameplayTag& InTag) {
}

UEnemy_AttackComponent::UEnemy_AttackComponent() {
    this->ChooseAttackBehaviorTree = NULL;
    this->DungeonDistanceScale = 0.50f;
    this->DungeonDistanceRangeScale = 0.65f;
    this->HistoryWeightScale = 1.00f;
    this->DistToRangeCurveWeightScale = 1.00f;
    this->WeaponSeekDistToTargetCurveWeightScale = 1.00f;
    this->HistoryRatioCurveWeight = NULL;
    this->DistToRangeCurveWeight = NULL;
    this->WeaponSeekDistToTargetCurveWeight = NULL;
}

