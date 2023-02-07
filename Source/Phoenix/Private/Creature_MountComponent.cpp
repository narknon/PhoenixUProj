#include "Creature_MountComponent.h"

class AActor;
class ACharacter;
class ACreatureMountHandler;

void UCreature_MountComponent::UpdateMoveInput(float DeltaTime) {
}

void UCreature_MountComponent::UpdateGroundMovement_Implementation(float DeltaTime) {
}

void UCreature_MountComponent::ToggleGallopTimedOut() {
}

void UCreature_MountComponent::TakeoffRequested(bool bSkipTakeoffAnimation) {
}

void UCreature_MountComponent::TakeOffPressed() {
}

void UCreature_MountComponent::StopVocalSfx(int32 InTransitionDuration) {
}

void UCreature_MountComponent::SpeedUpReleased() {
}

void UCreature_MountComponent::SpeedUpPressed(bool bSprintToggle) {
}


void UCreature_MountComponent::SetMinimumFlyingGait(EMountFlyingGait InMinimumFlyingGait) {
}

void UCreature_MountComponent::SetAutoLandingEnabled(bool bInEnabled) {
}

void UCreature_MountComponent::OnNearDeathKneel(AActor* Owner) {
}

void UCreature_MountComponent::OnMovementModeChanged(ACharacter* Character, TEnumAsByte<EMovementMode> PrevMovementMode, uint8 PreviousCustomMode) {
}

void UCreature_MountComponent::OnHealthChanged(AActor* Target, float InHealthChange, bool bIndicateHUD) {
}

void UCreature_MountComponent::LightAttackReleased() {
}

void UCreature_MountComponent::LightAttackPressed() {
}

void UCreature_MountComponent::LandingRequested() {
}

void UCreature_MountComponent::KeyboardWalkReleased() {
}

void UCreature_MountComponent::KeyboardWalkPressed() {
}

bool UCreature_MountComponent::IsFlying() const {
    return false;
}

EMountMovementState UCreature_MountComponent::GetMovementState() const {
    return EMountMovementState::Ground;
}

TEnumAsByte<EMovementMode> UCreature_MountComponent::GetMovementMode() const {
    return MOVE_None;
}

ACreatureMountHandler* UCreature_MountComponent::GetMountHandler() const {
    return NULL;
}

bool UCreature_MountComponent::GetFlyingDistanceAboveGround(float& OutDistanceAboveGround) const {
    return false;
}

void UCreature_MountComponent::DismountTriggered() {
}

void UCreature_MountComponent::DismountReleased() {
}

void UCreature_MountComponent::DismountPressed() {
}

void UCreature_MountComponent::DismountBeganHold() {
}

void UCreature_MountComponent::DeactivateMountComponent() {
}

bool UCreature_MountComponent::CanFly() const {
    return false;
}

bool UCreature_MountComponent::CanCharge() const {
    return false;
}

void UCreature_MountComponent::ActivateMountComponent(ACreatureMountHandler* InMountHandler, bool bInRiderIsPlayer) {
}

UCreature_MountComponent::UCreature_MountComponent() {
    this->HoverFlightGaitSpeed = 200.00f;
    this->SlowFlightGaitSpeed = 900.00f;
    this->FastFlightGaitSpeed = 1500.00f;
    this->CurrentFlyingGait = EMountFlyingGait::Slow;
    this->CurrentChargeState = EMountCombatChargeState::Inactive;
    this->CombatChargeActive = false;
    this->CombatChargeEnabled = false;
    this->CombatChargeRequestDuration = 0.00f;
    this->CombatChargeMinActiveDuration = 1.00f;
    this->CombatChargeCooldownDuration = 2.00f;
    this->CombatChargeRefillDelayDuration = 2.00f;
    this->CombatChargeRefillRate = 0.50f;
    this->CombatChargeDepletionRate = 1.00f;
    this->CombatChargeAmount_Max = 6.25f;
    this->CombatChargeAmount_SpawnsWith = 1.00f;
    this->CombatChargeAmount_MinUsable = 0.20f;
    this->CombatChargeWaterDepthLimit = 0.20f;
    this->CombatChargeRunOutSfx = NULL;
    this->CombatChargeNoChargeSfx = NULL;
    this->CombatChargePreSpecialAttackSfx = NULL;
    this->DeactiveSfxTransitionDuration = 250;
    this->HealthRefillDelayDuration = 2.00f;
    this->HealthRefillDuration = 600.00f;
    this->DeathTimeout = 600.00f;
    this->RiderCharacter = NULL;
    this->LandingDynamics = NULL;
    this->pChargeTriggerEffect = NULL;
    this->pJogTriggerEffect = NULL;
    this->DeadZone = 0.20f;
    this->TrotZone = 0.70f;
    this->ButtonHoldTime = 0.50f;
    this->ButtonTapTime = 0.20f;
    this->ToggleGallopTimeoutTime = 0.20f;
    this->MinInputTime = 0.16f;
    this->StickBounceMagnitudeThreshold = 0.80f;
    this->CameraRelativeAdjustmentAngle = -5.00f;
    this->WallCollisionImpactAngleThreshold = 45.00f;
    this->FlyingWallCollisionImpactAngleThreshold = 70.00f;
    this->NoMountZoneCollisionImpactAngleThreshold = 90.00f;
    this->FlightDynamics = NULL;
    this->FlyingAdditiveAbility = NULL;
    this->FlyingAdditiveChannel = TEXT("FullBodyAdditive");
    this->TailAdditiveAbility = NULL;
    this->TailAdditiveChannel = TEXT("AdditiveBody");
    this->MaxPitchForLevelFlight = 5.00f;
    this->MinSpeedForLevelFlight = 1000.00f;
    this->MaxPitchDegreesDownForFastFlightGait = 5.00f;
    this->MinGlideSpeedForFastFlightGait = 1700.00f;
    this->MinFlightTimeForAutoLanding = 1.00f;
    this->MaxSpeedForTrotLanding = 1500.00f;
    this->MaxInputMagnitudeForHover = 0.80f;
    this->MaxDeltaYawToAccelerateWhenHovering = 45.00f;
    this->VerticalHoverCollisionPredictionTime = 1.00f;
    this->bEnableAutoTakeoffWhenFalling = true;
    this->MinFallingTimeForAutoTakeoff = 0.50f;
    this->MinTimeToLandingForAutoTakeoff = 0.50f;
    this->HoverGaitCapsuleHalfHeight = 110.00f;
    this->HoverGaitCapsuleRadius = 55.00f;
    this->bEnableIdleBreaks = true;
    this->MinIdleTimeForIdleBreak = 10.00f;
    this->MinTimeBetweenIdleBreaks = 30.00f;
    this->MoveZ = 0.00f;
    this->InputTime = 0.00f;
    this->ReleaseTime = 0.00f;
    this->bStartedMoving = false;
    this->bUsingKeyboard = false;
    this->bToggleGallopRequested = false;
    this->MountHandler = NULL;
    this->OwnerCreatureCharacter = NULL;
    this->FlightMovementComponent = NULL;
    this->FlightAnimationComponent = NULL;
    this->MountStreamingComponent = NULL;
    this->MountHeightLimitComponent = NULL;
    this->MovementPredictionComponent = NULL;
}

