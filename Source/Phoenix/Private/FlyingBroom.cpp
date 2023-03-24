#include "FlyingBroom.h"

class ABiped_Player;
class ACharacter;
class AFlyingBroom;
class UCapsuleComponent;
class UFlyingBroomAudio;
class UFlyingBroomMovementComponent;
class UFlyingBroomPhysics;
class UObject;
class UScheduledEntity;
class USkeletalMeshComponent;
class USplineComponent;

void AFlyingBroom::UpdateRTPCValue(float InRTPCValue, const FString& RTPC, FVector2D ValueRange, FVector2D AudioValueRange) const {
}

void AFlyingBroom::UpdateBroomAudio_Implementation(UFlyingBroomAudio* BroomAudio) {
}

bool AFlyingBroom::Teleport(FVector DestLocation, float DestYaw, bool ResetCamera, bool TeleportPhysics) {
    return false;
}

void AFlyingBroom::SupressHoverDisabledUI(const bool bDisable) {
}

void AFlyingBroom::StartSettingMaxFlyHeightValue(float Value, EStandardManagedPriority Priority, UObject* InInstigator) const {
}

void AFlyingBroom::StartSettingForceHoverValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::StartSettingDismountAllowedValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::StartSettingDisableInputValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::StartSettingDisableBarrelRollValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::StartSettingBoostAllowedValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::ShowBroomHUD(bool bShow) const {
}

void AFlyingBroom::SetupPlayerOnBroom(ABiped_Player* BipedPlayer) {
}

void AFlyingBroom::SetupBroomComponents(UCapsuleComponent* Capsule, UFlyingBroomMovementComponent* Movement, USkeletalMeshComponent* Mesh) {
}

void AFlyingBroom::SetSplineComponent(USplineComponent* InSplineComponent, const bool bTeleportToStart) const {
}

void AFlyingBroom::SetScaleInfo(bool bInScaleIn, float InActiveScale) {
}

void AFlyingBroom::SetMaxFlyingSpeed(const float Speed) const {
}

void AFlyingBroom::SetForceLand(const bool bInForceLand) {
}

void AFlyingBroom::SafeDismountHeightCheck() {
}

void AFlyingBroom::RemoveRiderClothCollisionSources(const ACharacter* Character, bool bRemoveDelegates) {
}

void AFlyingBroom::PushFlightDataOntoStack(UFlyingBroomPhysics* NewFlightData) const {
}

void AFlyingBroom::PopFlightDataOffStack() const {
}






void AFlyingBroom::OnMountedNPCHiddenIsChanged(UScheduledEntity* inParticipant, bool inHidden) {
}





void AFlyingBroom::OnActorIsHiddenChanged(bool NewValue) {
}

bool AFlyingBroom::IsInTurbo() const {
    return false;
}

bool AFlyingBroom::IsInHoverMode() const {
    return false;
}

bool AFlyingBroom::IsInBoost() const {
    return false;
}

bool AFlyingBroom::IsForceLanding() const {
    return false;
}

bool AFlyingBroom::IsBoostRecharging() const {
    return false;
}

float AFlyingBroom::GetMaxBoostMeter() {
    return 0.0f;
}

TEnumAsByte<EFlyingBroomHitObjectType> AFlyingBroom::GetLastHitObject() const {
    return Unknown;
}

TEnumAsByte<EBroomDismountType> AFlyingBroom::GetDismountType() const {
    return DiveDismount;
}

float AFlyingBroom::GetBoostMeterAmount() {
    return 0.0f;
}

void AFlyingBroom::FinishSettingMaxFlyHeightValue(EStandardManagedPriority Priority, UObject* InInstigator) const {
}

void AFlyingBroom::FinishSettingForceHoverValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::FinishSettingDismountAllowedValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::FinishSettingDisableInputValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::FinishSettingDisableBarrelRollValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::FinishSettingBoostAllowedValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

void AFlyingBroom::EnableMovement() const {
}

void AFlyingBroom::EnableMountedRiderIKSetup(bool bEnabled) const {
}



void AFlyingBroom::DisableMovement() const {
}

void AFlyingBroom::DetachPlayerFromBroomOnDismount(ABiped_Player* BipedPlayer, AFlyingBroom* BroomProp, float VelocityDamping) {
}

bool AFlyingBroom::CanIdleBreak() const {
    return false;
}

void AFlyingBroom::BroomEvent(FName EventName) {
}

void AFlyingBroom::AttachPlayerToBroomOnMount(ABiped_Player* BipedPlayer, AFlyingBroom* BroomProp, TEnumAsByte<EBroomMountType> InMountType) {
}


bool AFlyingBroom::AllowDismount() {
    return false;
}

void AFlyingBroom::AIMountBroom(ACharacter* Character, UFlyingBroomPhysics* FlightData) {
}

void AFlyingBroom::AIDismountBroom() {
}

void AFlyingBroom::AddRiderClothCollisionSources(const ACharacter* Character) {
}

void AFlyingBroom::AddBoostPercentage(float Percent) {
}

void AFlyingBroom::AcceleratePressed() {
}

AFlyingBroom::AFlyingBroom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MountedCharacter = NULL;
    this->ActiveScale = 1.00f;
    this->bScaleIn = true;
    this->BroomPhysicAssetForRiderCloth = NULL;
    this->CapsuleComponent = NULL;
    this->BroomMeshComponent = NULL;
    this->BeaterMeshComponent = NULL;
    this->MovementComponent = NULL;
    this->MountStreamingComponent = NULL;
    this->MountHeightLimitComponent = NULL;
    this->AudioComponent = NULL;
    this->PlayerMountAbility = NULL;
    this->PlayerDismountDiveAbility = NULL;
    this->PlayerDismountGroundAbility = NULL;
    this->PlayerDismountGround2JogAbility = NULL;
    this->PlayerDismountInstantAbility = NULL;
    this->SwingBeaterAbility = NULL;
    this->SwingBeaterBackhandAbility = NULL;
    this->ThrowQuaffleAbility = NULL;
    this->StudentHoverBroomFlyAbility = NULL;
    this->StudentIdleAbility = NULL;
    this->FlyingBroomAudio = NULL;
    this->DeadZoneCurve = NULL;
    this->DeadZone = 0.20f;
    this->FastFlightInputEaseSpeed = 6.00f;
    this->GroundDismountHeight = 125.00f;
    this->MinCollisionResponseSpeed = 500.00f;
    this->IdleBreakTime = 6.00f;
    this->SpeedBoostUnavailableMessageTimeout = 1.50f;
    this->DecelerationInterpType = ECustomInterpType::EaseIn;
    this->DecelerationInterpSpeed = 0.50f;
    this->pBoostTriggerEffect = NULL;
    this->pSpeedUpTriggerEffect = NULL;
    this->pInactiveTriggerEffect = NULL;
    this->MountedAIControllerClass = NULL;
    this->EnemyAIController = NULL;
    this->StudentDefaultFlightData = NULL;
}

