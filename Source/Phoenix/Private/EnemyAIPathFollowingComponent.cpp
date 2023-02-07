#include "EnemyAIPathFollowingComponent.h"

class UActorComponent;

void UEnemyAIPathFollowingComponent::HandleComponentDeactivated(UActorComponent* InComponent) {
}

void UEnemyAIPathFollowingComponent::HandleComponentActivated(UActorComponent* InComponent, bool InSuccess) {
}

UEnemyAIPathFollowingComponent::UEnemyAIPathFollowingComponent() {
    this->PawnPtr = NULL;
    this->CharacterMoveCompPtr = NULL;
    this->EnemyCompPtr = NULL;
    this->ControllerPtr = NULL;
}

