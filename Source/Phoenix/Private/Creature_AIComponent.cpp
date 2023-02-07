#include "Creature_AIComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class ACreaturePerceptionVolume;
class ACreatureTetherVolume;
class APathNode;
class UAIPerceptionComponent;
class UAblAbility;
class UBlackboardComponent;
class UInteractionArchitectAsset;
class UObject;

void UCreature_AIComponent::TryEnterScheduledEntityMode() {
}

void UCreature_AIComponent::TeamChanged() {
}

void UCreature_AIComponent::StartFollowPathBehavior(APathNode* InPathNode) {
}

void UCreature_AIComponent::SetToWalkMovementSpeed() {
}

void UCreature_AIComponent::SetToSprintMovementSpeed() {
}

void UCreature_AIComponent::SetToMovementSpeedFloat(float InSpeed) {
}

void UCreature_AIComponent::SetToMovementSpeed(ECreatureMovementSpeed MovementSpeed) {
}

void UCreature_AIComponent::SetToJogMovementSpeed() {
}

void UCreature_AIComponent::SetTetherVolume(ACreatureTetherVolume* InTetherVolume) {
}

void UCreature_AIComponent::SetStoppingMode(ECreatureStoppingMode StoppingMode) {
}

void UCreature_AIComponent::SetPathEndMode(ECreaturePathEndMode PathEndMode) {
}

void UCreature_AIComponent::SetInteractionTime(AActor* InTargetActor) {
}

void UCreature_AIComponent::SetIdleOverrideState(ECreatureIdleOverrideState InNewState) {
}

void UCreature_AIComponent::SetFocusActorBlackboardState(AActor* FocusActor) {
}

void UCreature_AIComponent::SetDesiredCreatureStance(ECreatureStance InNewStance) {
}

void UCreature_AIComponent::SetAIState(ECreatureAIState InNewState) {
}

void UCreature_AIComponent::RemovePerceptionVolume(ACreaturePerceptionVolume* InPerceptionVolume) {
}

void UCreature_AIComponent::RandomizeApproachRadius() {
}

void UCreature_AIComponent::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors) {
}

void UCreature_AIComponent::OnObjectStateChange(const UObject* InCaller, uint8 InInteractiveAction) {
}

void UCreature_AIComponent::OnMunitionImpactDamage(const UObject* InCaller, const FMunitionImpactData& InImpactData) {
}

void UCreature_AIComponent::OnCreatureDied() {
}

void UCreature_AIComponent::OnAIStateComplete() {
}

ACreatureTetherVolume* UCreature_AIComponent::GetTetherVolume() {
    return NULL;
}

UAIPerceptionComponent* UCreature_AIComponent::GetPerceptionComponent() const {
    return NULL;
}

ECreaturePathEndMode UCreature_AIComponent::GetPathEndMode() const {
    return ECreaturePathEndMode::Stop;
}

ECreatureIdleOverrideState UCreature_AIComponent::GetIdleOverrideState() const {
    return ECreatureIdleOverrideState::None;
}

TSubclassOf<UAblAbility> UCreature_AIComponent::GetCustomAbilityClass() const {
    return NULL;
}

float UCreature_AIComponent::GetCurrentApproachRadius() {
    return 0.0f;
}

UBlackboardComponent* UCreature_AIComponent::GetBlackboard() const {
    return NULL;
}

ECreatureMovementSpeed UCreature_AIComponent::GetBestSpeedToReachLocation(FVector InLocation, float InTimeToReach) const {
    return ECreatureMovementSpeed::Stop;
}

ECreatureAIState UCreature_AIComponent::GetAIState() const {
    return ECreatureAIState::UtilitySelection;
}

void UCreature_AIComponent::FindPettingBrushInitialAttachment(const FGameplayTagContainer& InAnimationVariationTagContainer, FVector& OutRelativeLocation, FRotator& OutRotation, FVector& OutScale) const {
}

FTransform UCreature_AIComponent::FindPettingBrushAttachmentRelativeTransform() const {
    return FTransform{};
}

bool UCreature_AIComponent::ExecuteAbilityFromAsset(UInteractionArchitectAsset* InArchitectAsset) {
    return false;
}

void UCreature_AIComponent::EnableCreaturePerception() {
}

void UCreature_AIComponent::DisableCreaturePerception(bool bForgetPreviousStimuli, bool bLoseAwareness) {
}

void UCreature_AIComponent::AddPerceptionVolume(ACreaturePerceptionVolume* InPerceptionVolume) {
}

UCreature_AIComponent::UCreature_AIComponent() {
    this->IdleInteractionAsset = NULL;
    this->TetherRadius = 4000.00f;
    this->FleeRange = 3000.00f;
    this->FleeRunDistance = 3500.00f;
    this->FleeJogDistance = 5000.00f;
    this->FleeWalkDistance = 5000.00f;
    this->FleePathingDistance = 1000.00f;
    this->FleeScatterRadius = 400.00f;
    this->FleeHerdRadius = 200.00f;
    this->FleeDestinationOverride = NULL;
    this->bFadeWhenFleeing = false;
    this->ReactionInstigatorTagTime = 3.00f;
    this->FleeFlyingOption = ECreatureFleeFlyingOption::TakeoffImmediately;
    this->bIsFleeConstrainedByTether = false;
    this->MaximumFleeMovementSpeed = ECreatureMovementSpeed::Sprint;
    this->TurnApproachRadius = 300.00f;
    this->TrotApproachRadius = 1000.00f;
    this->RunApproachRadius = 2000.00f;
    this->InteractStance = ECreatureStance::LyingDown;
    this->PettingBrushAttachRelativeBoneName = TEXT("head");
    this->StartWithRestIdleBehaviorChance = 0.20f;
    this->StartWithRestIdleBehaviorAtNightChance = 0.60f;
    this->StartWithForageIdleBehaviorChance = 0.30f;
    this->MinExploreWaitTime = 0.00f;
    this->MaxExploreWaitTime = 5.00f;
    this->ExploreBehaviorLoopsMin = 2;
    this->ExploreBehaviorLoopsMax = 3;
    this->bTurnAnticipation = true;
    this->ForageBehaviorLoopsMin = 2;
    this->ForageBehaviorLoopsMax = 3;
    this->bCanForage = true;
    this->GroomOrLookAroundConsiderationMultiplier = 0.50f;
    this->GroomConsiderationMultiplier = 0.50f;
    this->RestBehaviorLoopsMin = 2;
    this->RestBehaviorLoopsMax = 3;
    this->FlightPreferredThresholdDistance = 500.00f;
    this->bShouldFlyOutOfWater = false;
    this->CirclingConsiderationMultiplier = 1.00f;
    this->CirclingWhenWildConsiderationBonus = 0.00f;
    this->MinCirclingHeightAboveGround = 800.00f;
    this->MaxCirclingHeightAboveGround = 1200.00f;
    this->MinCirclingRadiusMultiplier = 1.50f;
    this->MaxCirclingRadiusMultiplier = 2.50f;
    this->MinCirclingTime = 10.00f;
    this->MaxCirclingTime = 20.00f;
    this->bCanUsePerches = false;
    this->PerchingConsiderationMultiplier = 1.00f;
    this->PerchingWhenWildConsiderationBonus = 0.00f;
    this->MinPerchingSearchRadius = 1000.00f;
    this->MaxPerchingSearchRadius = 4000.00f;
    this->MinPerchingTime = 15.00f;
    this->MaxPerchingTime = 30.00f;
    this->bIsPerchingConstrainedByTether = true;
    this->Laziness = 0.50f;
    this->bIsNocturnal = false;
    this->bCanUseHerding = false;
    this->InitialHerdDetectionRadius = 3000.00f;
    this->bCanHerdSleep = false;
    this->bCanHerdFlee = false;
    this->bCanGraze = false;
    this->GrazingMinRadius = 300.00f;
    this->GrazingMaxRadius = 350.00f;
    this->StationaryGrazingDuration = 30.00f;
    this->RelaxStandingConsiderationMultiplier = 1.00f;
    this->RelaxSittingConsiderationMultiplier = 1.00f;
    this->RelaxLyingConsiderationMultiplier = 1.00f;
    this->RelaxSleepingConsiderationMultiplier = 1.00f;
    this->NurtureInteractCloseRange = 175.00f;
    this->NurtureInteractRange = 800.00f;
    this->NurtureInteractRangeHighHappinessMultiplier = 3.00f;
    this->NurtureInteractGreetTimeInterval = 300.00f;
    this->bStationaryForNurtureInteract = false;
    this->CombatMaxDistanceFromTether = 0.00f;
    this->CurrentCreatureSlot = NULL;
    this->BlackboardComponent = NULL;
    this->CreatureCharacter = NULL;
    this->CreatureController = NULL;
    this->NurtureComponent = NULL;
    this->CustomAbilityClass = NULL;
}

