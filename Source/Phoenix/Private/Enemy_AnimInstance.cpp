#include "Enemy_AnimInstance.h"

class UEnemyAISpawnData;

void UEnemy_AnimInstance::SetSpawnData_Implementation(UEnemyAISpawnData* InSpawnDataPtr) {
}

void UEnemy_AnimInstance::SetAttackTypeTag_Implementation(FGameplayTag InType) {
}

void UEnemy_AnimInstance::SetAnimDodgeState_Implementation(EEnemyAIDodgeState InDodgeState) {
}

UEnemyAISpawnData* UEnemy_AnimInstance::GetSpawnData_Implementation() const {
    return NULL;
}

FGameplayTag UEnemy_AnimInstance::GetAttackTypeTag_Implementation() const {
    return FGameplayTag{};
}

EEnemyAIDodgeState UEnemy_AnimInstance::GetAnimDodgeState_Implementation() {
    return EEnemyAIDodgeState::None;
}

bool UEnemy_AnimInstance::CanExitAttackLoop_Implementation() const {
    return false;
}

void UEnemy_AnimInstance::AnimNotify_ImpulseToTarget(float ActiveFrames, float DistFromTarget, float MaxTravelDist) {
}

UEnemy_AnimInstance::UEnemy_AnimInstance() {
    this->DodgeState = EEnemyAIDodgeState::None;
    this->WeaponActivateStoredIndex = 0;
    this->SpawnDataPtr = NULL;
    this->bOnGround = false;
}

