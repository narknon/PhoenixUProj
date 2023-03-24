#include "NonCombat_Character.h"

#include "NonCombat_MovementComponent.h"
#include "SocialAgentPathFollowerComponent.h"
#include "NPC_ReactionComponent.h"
#include "Templates/SubclassOf.h"

class UAblAbility;
class UAblReactionComponent;
class UAblReactionData;
class UCapsuleComponent;
class UObject;

void ANonCombat_Character::UnregisterForInteractionSense(UObject* InObject) {
}

void ANonCombat_Character::Suspend(const UObject* i_caller) {
}

void ANonCombat_Character::StopCustomAbility() {
}

void ANonCombat_Character::StopAndIdle(const UObject* i_caller) {
}

void ANonCombat_Character::StartChildSpawnFX_Implementation(FTransform inSpawnLoc) {
}

void ANonCombat_Character::Resume(const UObject* i_caller) {
}

void ANonCombat_Character::Release(const UObject* i_caller) {
}

void ANonCombat_Character::RegisterForInteractionSense(UObject* InObject) {
}

void ANonCombat_Character::PlayCustomAbility(TSubclassOf<UAblAbility> InAbility, bool bPreventReactions) {
}



void ANonCombat_Character::OnReactionQueued(UAblReactionData* InReactionData, UAblReactionComponent* InReactionComponent) {
}

void ANonCombat_Character::OnReactionEnd(UAblReactionData* InReactionData, UAblReactionComponent* InReactionComponent) {
}

void ANonCombat_Character::OnChildSpawnFX_Implementation(FTransform inSpawnLoc) {
}

bool ANonCombat_Character::IsSuspended() const {
    return false;
}

bool ANonCombat_Character::IsScheduledEntity() {
    return false;
}

bool ANonCombat_Character::IsReleased() const {
    return false;
}

bool ANonCombat_Character::IsFrozen() const {
    return false;
}

bool ANonCombat_Character::IsAlive() const {
    return false;
}

void ANonCombat_Character::HandleRagdollImpact(const UObject* i_caller) {
}

UCapsuleComponent* ANonCombat_Character::GetNpcCapsuleComponent_Implementation() {
    return NULL;
}

FVector ANonCombat_Character::GetImpactLocation() const {
    return FVector{};
}

FVector ANonCombat_Character::GetImpactDirection() const {
    return FVector{};
}

void ANonCombat_Character::Freeze(const UObject* i_caller) {
}

void ANonCombat_Character::ForceScheduledEntityState() {
}

void ANonCombat_Character::ForceProtego(bool inProtegoOnOff) {
}

void ANonCombat_Character::EnableCallout(const UObject* i_caller) {
}

void ANonCombat_Character::DisableCallout(const UObject* i_caller) {
}

void ANonCombat_Character::ApplySpawnFX_Implementation() {
}

void ANonCombat_Character::ApplyReplicaFX_Implementation() {
}

ANonCombat_Character::ANonCombat_Character(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UNonCombat_MovementComponent>(TEXT("CharMoveComp"))) {
    this->SocialAgentComponent = CreateDefaultSubobject<USocialAgentPathFollowerComponent>(TEXT("SocialAgentComponent"));
    this->CCComponent = NULL;
    this->CogSourceComp = NULL;
    this->NPCReactionComponent = CreateDefaultSubobject<UNPC_ReactionComponent>(TEXT("ReactionComponent"));
    this->bAllowDBInstanceRedirect = false;
    this->bCreateScheduledEntity = false;
    this->bIsAScheduledEntity = false;
    this->IdleAbility = NULL;
    this->MoveStartAbility = NULL;
    this->MoveAbility = NULL;
    this->PivotAbility = NULL;
    this->StairAbility = NULL;
    this->MoveStopAbility = NULL;
}

