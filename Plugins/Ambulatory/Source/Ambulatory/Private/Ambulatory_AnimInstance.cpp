#include "Ambulatory_AnimInstance.h"

void UAmbulatory_AnimInstance::WandCastInfo_ClearAttackCount() {
}

void UAmbulatory_AnimInstance::SetWandCastInfo_PreWandCastState(TEnumAsByte<EPreWandCastState::Type> PreWandCastState) {
}

void UAmbulatory_AnimInstance::SetWandCastInfo_AnticipationWandCastState(TEnumAsByte<EPreWandCastState::Type> AnticipationWandCastState) {
}

void UAmbulatory_AnimInstance::SetStartMoveTimeToCurrentTime_Implementation() {
}

void UAmbulatory_AnimInstance::SetPlayerIKState_Implementation(bool State) {
}

void UAmbulatory_AnimInstance::SetNextWandCastType(TEnumAsByte<EWandCastType::Type> WandCastType) {
}

void UAmbulatory_AnimInstance::SetLandingType_Implementation(ELandingType::Type InType) {
}

void UAmbulatory_AnimInstance::SetJumpingType_Implementation(EJumpingType::Type InType) {
}

void UAmbulatory_AnimInstance::SetIsViewAlignedWithDesiredDirection_Implementation(bool InFlag) {
}

void UAmbulatory_AnimInstance::SetIsAim_Implementation(bool InIsAim) {
}

void UAmbulatory_AnimInstance::SetIsActorAlignedWithDesiredDirection_Implementation(bool InFlag) {
}

void UAmbulatory_AnimInstance::SetIKStateWithEaseIn_Implementation(bool State, float Delay, float EaseTime) {
}

void UAmbulatory_AnimInstance::SetIKState_Implementation(bool State) {
}

void UAmbulatory_AnimInstance::SetGlobalIKState_Implementation(bool State) {
}

void UAmbulatory_AnimInstance::SetClimbingLedgeState_Implementation(EClimbingLedgeState::Type InType) {
}

void UAmbulatory_AnimInstance::SetClimbingLadderState_Implementation(EClimbingLadderState::Type InType) {
}

void UAmbulatory_AnimInstance::Set_WandCastMelee_Implementation(const bool bInFlag) {
}

void UAmbulatory_AnimInstance::Set_WalkRunLean_Implementation(float InWalkRunLean) {
}

void UAmbulatory_AnimInstance::Set_TrackingSpeed_Implementation(float InSpeed) {
}

void UAmbulatory_AnimInstance::Set_StopTurnDirection_Implementation(float InDirection) {
}

void UAmbulatory_AnimInstance::Set_StartTurnDirection_Implementation(float InDirection) {
}

void UAmbulatory_AnimInstance::Set_Speed_Implementation(float InSpeed) {
}

void UAmbulatory_AnimInstance::Set_ShortStepTrackingSpeed_Implementation(float InSpeed) {
}

void UAmbulatory_AnimInstance::Set_PlayRate_Implementation(float InPlayRate) {
}

void UAmbulatory_AnimInstance::Set_MobilityModeState_Implementation(EMobilityModeState::Type InState) {
}

void UAmbulatory_AnimInstance::Set_MobilityActionState_Implementation(EMobilityActionState::Type InState) {
}

void UAmbulatory_AnimInstance::Set_MaxSpeed_Implementation(float InMaxSpeed) {
}

void UAmbulatory_AnimInstance::Set_LookAtDirection_Implementation(float InDirection) {
}

void UAmbulatory_AnimInstance::Set_LastDesiredWorldSpeed_Implementation(float InSpeed) {
}

void UAmbulatory_AnimInstance::Set_IsTurningInPlace_Implementation(bool InFlag) {
}

void UAmbulatory_AnimInstance::Set_IsStrafing_Implementation(bool InFlag) {
}

void UAmbulatory_AnimInstance::Set_IsOverridenForCinematic_Implementation(bool InFlag) {
}

void UAmbulatory_AnimInstance::Set_IsMoving_Implementation(bool InIsMoving) {
}

void UAmbulatory_AnimInstance::Set_IsMovementInput_Implementation(bool InFlag) {
}

void UAmbulatory_AnimInstance::Set_ForceTurnAndFace_Implementation(bool InFlag) {
}

void UAmbulatory_AnimInstance::Set_FixedSpeed_Implementation(float InSpeed) {
}

void UAmbulatory_AnimInstance::Set_FixedDesiredDirection_Implementation(float InDirection) {
}

void UAmbulatory_AnimInstance::Set_DesiredHorizontalBodyLean_Implementation(float InDesiredHorizontalBodyLean) {
}

void UAmbulatory_AnimInstance::Set_DesiredForwardBodyLean_Implementation(float InDesiredForwardBodyLean) {
}

void UAmbulatory_AnimInstance::Set_DesiredDirection_Implementation(float InDirection) {
}

void UAmbulatory_AnimInstance::Set_DesiredBodyTurn_Implementation(float InDesiredBodyTurn) {
}

void UAmbulatory_AnimInstance::Set_AimLeanYaw_Implementation(float InAimLeanYaw) {
}

void UAmbulatory_AnimInstance::Set_AimLeanPitch_Implementation(float InAimLeanPitch) {
}

void UAmbulatory_AnimInstance::Revert_MobilityModeState_Implementation() {
}

void UAmbulatory_AnimInstance::Revert_MobilityActionState_Implementation() {
}

void UAmbulatory_AnimInstance::InitRootMotionModifierVectors_Implementation() {
}

TEnumAsByte<EPreWandCastState::Type> UAmbulatory_AnimInstance::GetWandCastInfo_AnticipationWandCastState() {
    return EPreWandCastState::None;
}

bool UAmbulatory_AnimInstance::GetPlayerIKState_Implementation() {
    return false;
}

void UAmbulatory_AnimInstance::GetLandingType_Implementation(TEnumAsByte<ELandingType::Type>& OutType) {
}

void UAmbulatory_AnimInstance::GetJumpingType_Implementation(TEnumAsByte<EJumpingType::Type>& OutType) {
}

bool UAmbulatory_AnimInstance::GetIKState_Implementation() {
    return false;
}

bool UAmbulatory_AnimInstance::GetGlobalIKState_Implementation() {
    return false;
}

void UAmbulatory_AnimInstance::GetClimbingLedgeState_Implementation(TEnumAsByte<EClimbingLedgeState::Type>& OutType) {
}

void UAmbulatory_AnimInstance::GetClimbingLadderState_Implementation(TEnumAsByte<EClimbingLadderState::Type>& OutType) {
}

bool UAmbulatory_AnimInstance::Get_WandCastMelee_Implementation() {
    return false;
}

float UAmbulatory_AnimInstance::Get_WalkRunLean_Implementation() {
    return 0.0f;
}

void UAmbulatory_AnimInstance::Get_StopTurnDirection_Implementation(float& OutDirection) {
}

void UAmbulatory_AnimInstance::Get_StartTurnDirection_Implementation(float& OutDirection) {
}

void UAmbulatory_AnimInstance::Get_Speed_Implementation(float& OutSpeed) {
}

void UAmbulatory_AnimInstance::Get_PrevMobilityModeState_Implementation(TEnumAsByte<EMobilityActionState::Type>& OutState) {
}

void UAmbulatory_AnimInstance::Get_PrevMobilityActionState_Implementation(TEnumAsByte<EMobilityActionState::Type>& OutState) {
}

void UAmbulatory_AnimInstance::Get_PlayRate_Implementation(float& OutPlayRate) {
}

void UAmbulatory_AnimInstance::Get_MobilityModeState_Implementation(TEnumAsByte<EMobilityActionState::Type>& OutState) {
}

void UAmbulatory_AnimInstance::Get_MobilityActionState_Implementation(TEnumAsByte<EMobilityActionState::Type>& OutState) {
}

void UAmbulatory_AnimInstance::Get_MaxSpeed_Implementation(float& OutMaxSpeed) {
}

void UAmbulatory_AnimInstance::Get_LookAtDirection_Implementation(float& OutDirection) {
}

void UAmbulatory_AnimInstance::Get_Lean_Implementation(float& OutAimLeanYaw, float& OutAimLeanPitch) {
}

void UAmbulatory_AnimInstance::Get_LastDesiredWorldSpeed_Implementation(float& OutSpeed) {
}

void UAmbulatory_AnimInstance::Get_IsTurningInPlace_Implementation(bool& OutFlag) {
}

void UAmbulatory_AnimInstance::Get_IsMoving_Implementation(bool& InIsMoving) {
}

void UAmbulatory_AnimInstance::Get_IsMovementInput_Implementation(bool& OutFlag) {
}

void UAmbulatory_AnimInstance::Get_FixedSpeed_Implementation(float& OutSpeed) {
}

void UAmbulatory_AnimInstance::Get_DesiredDirection_Implementation(float& OutDirection) {
}

void UAmbulatory_AnimInstance::AnimNotify_TurnAssistOn() {
}

void UAmbulatory_AnimInstance::AnimNotify_TurnAssistOff() {
}

void UAmbulatory_AnimInstance::AnimNotify_StartMoveBegin() {
}

void UAmbulatory_AnimInstance::AnimNotify_SetStrafing() {
}

void UAmbulatory_AnimInstance::AnimNotify_MoveEnd() {
}

void UAmbulatory_AnimInstance::AnimNotify_MoveBegin() {
}

void UAmbulatory_AnimInstance::AnimNotify_LeftIdle() {
}

void UAmbulatory_AnimInstance::AnimNotify_LandingFinished() {
}

void UAmbulatory_AnimInstance::AnimNotify_JumpStarted() {
}

void UAmbulatory_AnimInstance::AnimNotify_JumpFinished() {
}

void UAmbulatory_AnimInstance::AnimNotify_IdleBegin() {
}

UAmbulatory_AnimInstance::UAmbulatory_AnimInstance() {
    this->MobilityModeState = EMobilityModeState::FreeRoam;
    this->PrevMobilityModeState = EMobilityModeState::FreeRoam;
    this->bPartialBodyUseAbilitiesTest = true;
    this->MobilityActionState = EMobilityActionState::IsIdle;
    this->PrevMobilityActionState = EMobilityActionState::IsIdle;
    this->JumpType = EJumpingType::None;
    this->LandType = ELandingType::None;
    this->AnimSpeedType = EAnimSpeedType::Stopped;
    this->AnimMechanicType = EAnimMechanicType::Idle;
    this->ClimbingLedgeState = EClimbingLedgeState::None;
    this->ClimbingLadderState = EClimbingLadderState::None;
    this->StrafeAngle = 0.00f;
    this->IsMoving = false;
    this->IsAim = false;
    this->IsMovementInput = false;
    this->IsTurningInPlace = false;
    this->IsStrafing = false;
    this->DesiredIsStrafing = false;
    this->ForceTurnAndFace = false;
    this->BlockedByWall = false;
    this->IsViewAlignedWithDesiredDirection = true;
    this->IsActorAlignedWithDesiredDirection = true;
    this->LookAtDirection = 0.00f;
    this->DesiredDirection = 0.00f;
    this->InterpedDesiredDirection = 0.00f;
    this->LastDesiredDirection = 0.00f;
    this->FixedDesiredDirection = 0.00f;
    this->StopTurnDirection = 0.00f;
    this->StartTurnDirection = 0.00f;
    this->WalkRunLean = 0.00f;
    this->Speed = 0.00f;
    this->FixedSpeed = 0.00f;
    this->TrackingSpeed = 0.00f;
    this->ShortStepTrackingSpeed = 0.00f;
    this->LastDesiredWorldSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
    this->PlayRate = 1.00f;
    this->DesiredForwardBodyLean = 0.00f;
    this->DesiredHorizontalBodyLean = 0.00f;
    this->DesiredBodyTurn = 0.00f;
    this->GameTimeAtStartMove = 0.00f;
    this->GameTimeAtStopMove = 0.00f;
    this->AimLeanYaw = 0.00f;
    this->AimLeanPitch = 0.00f;
    this->JumpHeight = 0.00f;
    this->IsFlicked = false;
    this->IsOverridenForCinematic = false;
    this->IsInIdle = false;
    this->LookAtTargetPitch = 0.00f;
    this->LookAtTargetYaw = 0.00f;
    this->HasLookAtTarget = false;
    this->bUsingStairsAnims = false;
}

