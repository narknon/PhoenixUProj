#include "Icarus3DMovementComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class UAblAbility;

float UIcarus3DMovementComponent::GetTurningCircleRadius() const {
    return 0.0f;
}

void UIcarus3DMovementComponent::EnableFlying() {
}

void UIcarus3DMovementComponent::DisableFlying(bool bSwitchToGroundNavigation) {
}

void UIcarus3DMovementComponent::BehaviorTakeOffStart(TSubclassOf<UAblAbility> TakeOffAbility, bool bTeleportIfNoTakeOffAbility) {
}

void UIcarus3DMovementComponent::BehaviorStop(EBehaviorResult::Type Result) {
}

void UIcarus3DMovementComponent::BehaviorLandingLocationStart(FVector LocationToLandAt, float Height) {
}

void UIcarus3DMovementComponent::BehaviorLandingActorStart(AActor* ActorToLandAt, float Height, float ActorUpdateDistance) {
}

void UIcarus3DMovementComponent::BehaviorCircleLocationStart(FVector CircleCenterLocation, float Radius, float Height, bool bClockwise, bool bLookAtCirclingLocation, float LookAtMaxPitch) {
}

void UIcarus3DMovementComponent::BehaviorCircleActorStart(AActor* CircleCenterActor, float Radius, float Height, bool bClockwise, bool bLookAtCirclingActor, float LookAtMaxPitch, float ActorUpdateDistance) {
}

UIcarus3DMovementComponent::UIcarus3DMovementComponent() {
    this->bCanEverFly = true;
    this->DefaultTakeOffAbility = NULL;
    this->DefaultTakeOffAbilityOverride = NULL;
    this->bStartFlying = false;
}

