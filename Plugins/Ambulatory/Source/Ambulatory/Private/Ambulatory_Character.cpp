#include "Ambulatory_Character.h"

#include "Ambulatory_MovementComponent.h"
#include "TargetTracker.h"

class UAnimInstance;
class UObject;
class UPrimitiveComponent;
class USceneComponent;

void AAmbulatory_Character::StopWorldTurnInPlace_Implementation() {
}

void AAmbulatory_Character::StartWorldTurnInPlace_Implementation(FVector WorldDirection) {
}

void AAmbulatory_Character::SprintStop_Implementation() {
}

void AAmbulatory_Character::SprintStart_Implementation(ESpeedModifierType::Type SpeedModType) {
}

void AAmbulatory_Character::ShowTimingMessage(const FString& MyMessage, UObject* WorldContextObject, float Duration) {
}

void AAmbulatory_Character::SetWorldSpeedAndDirection(float WorldSpeed, FVector WorldDirection) {
}

void AAmbulatory_Character::SetWorldSpeed(float WorldSpeed) {
}

void AAmbulatory_Character::SetUseSpeedModifier_Implementation(bool bUseSpeedModifier) {
}

void AAmbulatory_Character::SetTargetSpeedAndDirection(const float InAbstractSpeed, const FVector InDirection, bool InSetMobilityStateBasedOnSpeed) {
}

void AAmbulatory_Character::SetTargetSpeed(float InAbstractSpeed, bool InSetMobilityStateBasedOnSpeed) {
}

void AAmbulatory_Character::SetSpeedMode_Implementation(ETargetSpeedMode::Type SpeedMode, ETargetSpeedMode::Type SpeedModifier, ETargetSpeedPriority::Type SpeedPriority) {
}

void AAmbulatory_Character::SetMovementSpeeds_Implementation(float InMin, float InMax) {
}

void AAmbulatory_Character::SetMountTransform_Implementation(const FTransform& Transform) {
}

void AAmbulatory_Character::SetMountNormal_Implementation(const FVector& Normal) {
}

void AAmbulatory_Character::SetMobilityModeState_Implementation(EMobilityActionState::Type InMobilityModeState) {
}

void AAmbulatory_Character::SetMobilityActionState_Implementation(EMobilityActionState::Type InMobilityActionState, bool bSetTargetSpeed) {
}

void AAmbulatory_Character::SetLandingType_Implementation(ELandingType::Type InType) {
}

void AAmbulatory_Character::SetJumpingType_Implementation(const TEnumAsByte<EJumpingType::Type>& InType) {
}

void AAmbulatory_Character::SetIsInIdle_Implementation(const bool isIdle) {
}

void AAmbulatory_Character::SetInWaterVolume_Implementation(const bool InFlag) {
}

void AAmbulatory_Character::SetDesiredDirection_Implementation(const FVector InWorldDirection) {
}

void AAmbulatory_Character::SetClimbingLedgeState_Implementation(EClimbingLedgeState::Type InType) {
}

void AAmbulatory_Character::SetClimbingLadderState_Implementation(EClimbingLadderState::Type InType) {
}

void AAmbulatory_Character::SetBaseSpeedMode_Implementation(ETargetSpeedMode::Type SpeedMode, ETargetSpeedMode::Type SpeedModifier) {
}

void AAmbulatory_Character::Set_ForceTurnAndFace_Implementation(bool InFlag) {
}

void AAmbulatory_Character::RevertSpeedMode_Implementation(ETargetSpeedPriority::Type SpeedPriority) {
}

void AAmbulatory_Character::RevertMobilityModeState_Implementation() {
}

void AAmbulatory_Character::RevertMobilityActionState_Implementation(bool bSetTargetSpeed) {
}

void AAmbulatory_Character::RemoveWadingComponent(UPrimitiveComponent* InWaterComponent) {
}

void AAmbulatory_Character::JumpStarted_Implementation(UAnimInstance* InAnimInstance) {
}

void AAmbulatory_Character::JumpFinished_Implementation(UAnimInstance* InAnimInstance) {
}

bool AAmbulatory_Character::IsWadingComponent(UPrimitiveComponent* InWaterComponent) const {
    return false;
}

bool AAmbulatory_Character::IsUsingSpeedModifier_Implementation() {
    return false;
}

int32 AAmbulatory_Character::GetWadingComponentCount() const {
    return 0;
}

UPrimitiveComponent* AAmbulatory_Character::GetWadingComponent() const {
    return NULL;
}

void AAmbulatory_Character::GetTargetSpeedModifier_Implementation(TEnumAsByte<ETargetSpeedMode::Type>& OutState) {
}

ESpeedModifierType::Type AAmbulatory_Character::GetSpeedModifierType_Implementation() {
    return ESpeedModifierType::None;
}

void AAmbulatory_Character::GetPreviousMobilityActionState_Implementation(TEnumAsByte<EMobilityActionState::Type>& OutMobilityActionState) {
}

FOdcPathSpec AAmbulatory_Character::GetPathSpec() const {
    return FOdcPathSpec{};
}

void AAmbulatory_Character::GetMountTransform_Implementation(FTransform& LedgeTransform) {
}

void AAmbulatory_Character::GetMountNormal_Implementation(FVector& LedgeNormal) {
}

void AAmbulatory_Character::GetMobilityModeState_Implementation(TEnumAsByte<EMobilityActionState::Type>& OutMobilityModeState) {
}

void AAmbulatory_Character::GetMobilityActionStateName(UAnimInstance* InAnimInstance, FString& OutString) {
}

void AAmbulatory_Character::GetMobilityActionState_Implementation(TEnumAsByte<EMobilityActionState::Type>& OutMobilityActionState) {
}

UTargetTracker* AAmbulatory_Character::GetLookAtTargetTracker_Implementation() {
    return NULL;
}

int32 AAmbulatory_Character::GetLinkUsageFlags_Implementation() const {
    return 0;
}

void AAmbulatory_Character::GetLedgeTransform_Implementation(FTransform& LedgeTransform) {
}

void AAmbulatory_Character::GetLedgeNormal_Implementation(FVector& LedgeNormal) {
}

void AAmbulatory_Character::GetLandingType_Implementation(TEnumAsByte<ELandingType::Type>& OutType) {
}

void AAmbulatory_Character::GetJumpingType_Implementation(TEnumAsByte<EJumpingType::Type>& OutType) {
}

bool AAmbulatory_Character::GetIsMovementInput_Implementation() {
    return false;
}

bool AAmbulatory_Character::GetIsInIdle_Implementation() {
    return false;
}

UTargetTracker* AAmbulatory_Character::GetFaceTargetTracker_Implementation() {
    return NULL;
}

void AAmbulatory_Character::GetClimbingLedgeState_Implementation(TEnumAsByte<EClimbingLedgeState::Type>& OutType) {
}

void AAmbulatory_Character::GetClimbingLadderState_Implementation(TEnumAsByte<EClimbingLadderState::Type>& OutType) {
}

int32 AAmbulatory_Character::GetBlockageFlags_Implementation() const {
    return 0;
}

void AAmbulatory_Character::GetBaseSpeedMode_Implementation(TEnumAsByte<ETargetSpeedMode::Type>& OutState) {
}

UTargetTracker* AAmbulatory_Character::GetAimAtTargetTracker_Implementation() {
    return NULL;
}

void AAmbulatory_Character::DestroyAttachedSceneComponent_Implementation(USceneComponent* InSceneComponent) {
}

float AAmbulatory_Character::ComputeDesiredDirectionAngle(const FVector& InDirection, const bool bInComputeDegrees) const {
    return 0.0f;
}

float AAmbulatory_Character::ComputeAngleBetweenTargetTrackers(UTargetTracker* SourceTracker, UTargetTracker* DestTracker, const bool bInComputeDegrees) {
    return 0.0f;
}

float AAmbulatory_Character::ComputeAngle(const FVector& InDirection, const FVector& InSourceForward, const bool bInComputeDegrees) const {
    return 0.0f;
}

void AAmbulatory_Character::CharacterRotatedBySupport(FRotator DeltaRotation) {
}

USceneComponent* AAmbulatory_Character::AttachSceneComponent_Implementation(FTransform InTransform, FName InTag) {
    return NULL;
}

void AAmbulatory_Character::ApplySlideHorizontalMovement(float WorldSpeed, const FVector InWorldDirection) {
}

void AAmbulatory_Character::ApplyMobilityModeStateSpeeds_Implementation(EMobilityModeState::Type InMobilityModeState) {
}

bool AAmbulatory_Character::AmIMovingIntoStairs() const {
    return false;
}

bool AAmbulatory_Character::AmIMovingIntoSlopes() const {
    return false;
}

bool AAmbulatory_Character::AmIGoingUpStairs() const {
    return false;
}

bool AAmbulatory_Character::AmIGoingDownStairs() const {
    return false;
}

void AAmbulatory_Character::AddWadingComponent(UPrimitiveComponent* InWaterComponent) {
}

AAmbulatory_Character::AAmbulatory_Character(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UAmbulatory_MovementComponent>(TEXT("CharMoveComp"))) {
    this->AkEvent = NULL;
    this->FootPlantEffects = NULL;
    this->bIsBiped = true;
    this->bUseTurnAssist = true;
    this->bAbstractMobility = false;
    this->bTestNewMobilityMotions = false;
    this->bOnlyLockOnMode = true;
    this->MinimumMovementSpeed = 95.00f;
    this->MaximumMovementSpeed = 450.00f;
    this->SlowWalkMovementSpeed = 95.00f;
    this->WalkMovementSpeed = 156.00f;
    this->FastWalkMovementSpeed = 240.00f;
    this->JogMovementSpeed = 450.00f;
    this->SprintMovementSpeed = 580.00f;
    this->AmbulatoryData = NULL;
    this->JumpStartHeight = 0.00f;
    this->Debug = false;
    this->LadderActor = NULL;
    this->LookAtTargetTracker = CreateDefaultSubobject<UTargetTracker>(TEXT("LookAtTargetTracker"));
    this->FaceTargetTracker = CreateDefaultSubobject<UTargetTracker>(TEXT("FaceTargetTracker"));
    this->AimAtTargetTracker = CreateDefaultSubobject<UTargetTracker>(TEXT("AimAtTargetTracker"));
    this->SpeedModeTracker = NULL;
    this->SpeedModifierTracker = NULL;
    this->m_navLinkUsingLedge = false;
    this->m_linkType = ELinkType::JUMP_LINK;
    this->m_traceWallRadius = 35.00f;
    this->m_traceWallDropRadius = 50.00f;
    this->m_traceWallForward = 150.00f;
    this->m_traceWallHeightAdjust = 50.00f;
    this->m_traceLedgeRadius = 20.00f;
    this->m_traceLedgeIntoWallAdjust = 30.00f;
    this->m_traceLedgeUpAdjust = 600.00f;
    this->m_traceLedgeDownCast = 550.00f;
}

