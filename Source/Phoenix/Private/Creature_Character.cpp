#include "Creature_Character.h"
#include "AnimationComponent.h"
#include "EnemyStateComponent.h"

class AActor;
class UCreature_MountComponent;

bool ACreature_Character::StartFire_Implementation(float Amount, FVector Location) {
    return false;
}

void ACreature_Character::ShowCreatureFollowScreen() {
}

void ACreature_Character::SetCanUseIdleBreaksDefaultValue(bool bValue) {
}

bool ACreature_Character::SetAvoidanceAgainst(AActor* Actor, bool bEnable) {
    return false;
}

void ACreature_Character::OnFireExtinguished_Implementation() {
}

void ACreature_Character::OnCompletelyCharred_Implementation() {
}

bool ACreature_Character::IsActivePlayerMount() const {
    return false;
}

bool ACreature_Character::GetTrackerIsStationary() {
    return false;
}

float ACreature_Character::GetTrackerAverageSpeed() {
    return 0.0f;
}

UCreature_MountComponent* ACreature_Character::GetMountComponent() const {
    return NULL;
}



ACreature_Character::ACreature_Character(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
    this->EnemyStateComponent = CreateDefaultSubobject<UEnemyStateComponent>(TEXT("EnemyStateComponent"));
    this->FlightMotionTable = NULL;
    this->bRecordLastReceivedAnimNotify = false;
    this->StartState = ECreatureAIInitialState::Auto;
    this->bStartTame = false;
    this->StartPathNode = NULL;
    this->Cage = NULL;
    this->CageAnimation = ECreatureCageAnimation::Alert;
    this->SpawnVFX = NULL;
    this->bSpawnFlying = false;
    this->bSpawnPerched = false;
    this->bOverrideGender = false;
    this->bIsMaleOverride = true;
    this->RootMotionTranslationScale = 1.00f;
    this->DesiredFlightState = ECreatureFlightState::NotFlying;
    this->DesiredLandingType = ECreatureLandingType::None;
    this->DesiredStoppingMode = ECreatureStoppingMode::Rapid;
    this->ActualStoppingMode = ECreatureStoppingMode::Rapid;
    this->DesiredMovementSpeed = ECreatureMovementSpeed::Stop;
    this->CreatureAIComponent = NULL;
    this->NurtureComponent = NULL;
    this->CombatComponent = NULL;
    this->FlightMovementComponent = NULL;
    this->FlightNavigationComponent = NULL;
    this->FlightAnimationComponent = NULL;
    this->CentaurCombatComponent = NULL;
    this->MountComponent = NULL;
    this->bTestForAudioOcclusion = true;
    this->MaxConcurrentAkComponents = 1;
    this->MaxAkEventsPerFrame = 3;
    this->CreatedCalloutAttachComponent = NULL;
    this->OcclusionAkComponent = NULL;
    this->MotionAkComponent = NULL;
}

