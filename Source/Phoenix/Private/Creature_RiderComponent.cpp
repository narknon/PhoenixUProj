#include "Creature_RiderComponent.h"

class ACreatureMountHandler;
class ACreature_Character;
class UAblReactionComponent;
class UAblReactionData;
class UCreature_MountComponent;

void UCreature_RiderComponent::OnMountMovementStateChanged(UCreature_MountComponent* MountComponent, EMountMovementState PrevMovementState) {
}

void UCreature_RiderComponent::OnCreatureReactionQueued(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent) {
}

void UCreature_RiderComponent::InterruptDismount() {
}

ACreatureMountHandler* UCreature_RiderComponent::GetMountHandler() const {
    return NULL;
}

ACreature_Character* UCreature_RiderComponent::GetCreatureCharacter() const {
    return NULL;
}

void UCreature_RiderComponent::EnableHandIK() {
}

void UCreature_RiderComponent::DisableHandIK() {
}

void UCreature_RiderComponent::DeactivateRiderComponent() {
}

void UCreature_RiderComponent::ActivateRiderComponent(ACreatureMountHandler* InMountHandler, const bool bEnableHandIK) {
}

UCreature_RiderComponent::UCreature_RiderComponent() {
    this->HeadTurnAbility = NULL;
    this->HeadTurnAbilityChannelName = TEXT("FullBodyAdditive");
    this->FlyAdditiveAbility = NULL;
    this->FlyAdditiveAbilityChannelName = TEXT("AdditiveBody");
    this->RiderAnimationSetArchitectAsset = NULL;
    this->InitialGroundAbility = NULL;
    this->InitialFlyingAbility = NULL;
    this->bUseHandIK = false;
    this->bEnableAnimationModifier = true;
    this->HipsBoneName = TEXT("Hips");
    this->LeftThighBoneName = TEXT("LeftUpLeg");
    this->RightThighBoneName = TEXT("RightUpLeg");
    this->PitchCorrectionSpringFrequency = 10.00f;
}

