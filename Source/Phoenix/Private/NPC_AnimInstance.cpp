#include "NPC_AnimInstance.h"

class AActor;
class AAmbulatory_Character;

void UNPC_AnimInstance::SetState_Implementation(const EEnemyAIAnimState& InState) {
}

void UNPC_AnimInstance::SetMainState_Implementation(const EEnemy_AnimMainState& InState) {
}

void UNPC_AnimInstance::SetAnimSpawnState_Implementation(ENPC_SpawnState InAnimSpawnState) {
}

void UNPC_AnimInstance::SetAbilityActive_Implementation(EEnemy_Ability InAbility, bool bUse) {
}

void UNPC_AnimInstance::OnTeleport(AAmbulatory_Character* Character, FVector AmountDisplaced, FRotator AmountRotated) {
}

void UNPC_AnimInstance::HandleHeadTracking_Implementation(AActor* Owner) {
}

EEnemyAIAnimState UNPC_AnimInstance::GetState_Implementation() const {
    return EEnemyAIAnimState::Idle;
}

EEnemy_AnimMainState UNPC_AnimInstance::GetMainState_Implementation() const {
    return EEnemy_AnimMainState::None;
}

ENPC_SpawnState UNPC_AnimInstance::GetAnimSpawnState_Implementation() const {
    return ENPC_SpawnState::None;
}

EEnemy_Ability UNPC_AnimInstance::GetActiveAbility_Implementation() const {
    return EEnemy_Ability::Idle;
}

bool UNPC_AnimInstance::GetAbilityActive_Implementation(EEnemy_Ability InAbility) const {
    return false;
}

UNPC_AnimInstance::UNPC_AnimInstance() {
    this->State = EEnemyAIAnimState::Idle;
    this->LastState = EEnemyAIAnimState::Idle;
    this->MainState = EEnemy_AnimMainState::None;
    this->LastMainState = EEnemy_AnimMainState::None;
    this->LookAtAlpha = 0.00f;
    this->ParryAnimTime = 0.00f;
    this->bParryAnimTimeSet = false;
    this->SpawnState = ENPC_SpawnState::None;
    this->ActiveAbility = EEnemy_Ability::Idle;
}

