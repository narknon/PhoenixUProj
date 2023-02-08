#include "Biped_AnimInstance.h"

class AActor;
class APickupTool;

void UBiped_AnimInstance::StartSettingCinematicRightArmState_Implementation(ERightArmState::Type InState, bool bBroadcastChange) {
}

void UBiped_AnimInstance::StartSettingCinematicLeftArmState_Implementation(ELeftArmState::Type InState, bool bBroadcastChange) {
}

void UBiped_AnimInstance::SetWandEquipped_Implementation(bool WandEquipped) {
}

void UBiped_AnimInstance::SetUseAimOffset_Implementation(bool InUseAimOffset) {
}

void UBiped_AnimInstance::SetStationState_Implementation(const TEnumAsByte<EStationState::Type>& InState) {
}

void UBiped_AnimInstance::SetStationMode_Implementation(const TEnumAsByte<EStationMode::Type>& InMode) {
}

void UBiped_AnimInstance::SetRightArmState_Implementation(ERightArmState::Type InState, ERightArmPriority::Type InPriority, bool bBroadcastChange) {
}

void UBiped_AnimInstance::SetPickupTool_Implementation(APickupTool* InPickupTool) {
}

void UBiped_AnimInstance::SetPartialBodyState_Implementation(const TEnumAsByte<EPartialBodyState::Type>& InState) {
}

void UBiped_AnimInstance::SetParryStateNext_Implementation(const TEnumAsByte<EParryState::Type>& InState) {
}

void UBiped_AnimInstance::SetParryState_Implementation(const TEnumAsByte<EParryState::Type>& InState) {
}

void UBiped_AnimInstance::SetMobilityStateLast_Implementation(const TEnumAsByte<EMobilityState::Type>& InState) {
}

void UBiped_AnimInstance::SetMobilityState_Implementation(const TEnumAsByte<EMobilityState::Type>& InState) {
}

void UBiped_AnimInstance::SetLeftArmState_Implementation(ELeftArmState::Type InState, ELeftArmPriority::Type InPriority, bool bBroadcastChange) {
}

void UBiped_AnimInstance::SetIsHoldingAttack_Implementation(bool InHoldingAttack) {
}

void UBiped_AnimInstance::SetInventoryResult_Implementation(const FInventoryResult InInventoryResult) {
}

void UBiped_AnimInstance::SetHeadTrackingState_Implementation(EHeadTrackingState::Type InState, EHeadTrackingPriority::Type InPriority, bool bBroadcastChange) {
}

void UBiped_AnimInstance::SetHarvestState_Implementation(const TEnumAsByte<EHarvestState::Type>& InState) {
}

void UBiped_AnimInstance::SetFullBodyStateLast_Implementation(const TEnumAsByte<EFullBodyState::Type>& InState) {
}

void UBiped_AnimInstance::SetFullBodyState_Implementation(const TEnumAsByte<EFullBodyState::Type>& InState) {
}

void UBiped_AnimInstance::SetDodgeState_Implementation(const TEnumAsByte<EDodgeState::Type>& InState) {
}

void UBiped_AnimInstance::SetCombatAdditiveState_Implementation(ECombatAdditiveState::Type InState, ECombatAdditivePriority::Type InPriority, bool bBroadcastChange) {
}

void UBiped_AnimInstance::SetAttackState_Implementation(const TEnumAsByte<EAttackState::Type>& InState) {
}

void UBiped_AnimInstance::SetAmpedPercent_Implementation(float InAmpedPercent) {
}

void UBiped_AnimInstance::SetAdditiveBodyState_Implementation(const TEnumAsByte<EAdditiveBodyState::Type>& InState) {
}

void UBiped_AnimInstance::SetAbortAnim_Implementation(bool InAbortAnim) {
}

void UBiped_AnimInstance::Set_DoFullBodySpellIfInIdle_Implementation(bool bInDoFullBodySpellIfInIdle) {
}

void UBiped_AnimInstance::Set_AimOffsetYaw_Implementation(const float& InYaw) {
}

void UBiped_AnimInstance::Set_AimOffsetPitch_Implementation(const float& InPitch) {
}

void UBiped_AnimInstance::PushNewBasicMobilityMode(const int32 UniqueIDOverride, int32& UniqueId, TEnumAsByte<EBasicMobilityMode::Type> Mode) {
}

void UBiped_AnimInstance::PopBasicMobilityMode(int32 UniqueId) {
}

void UBiped_AnimInstance::OnLeftArmStateChanged(TEnumAsByte<ELeftArmState::Type> InLeftArmState) {
}

void UBiped_AnimInstance::OnCombatAdditiveStateChanged(TEnumAsByte<ECombatAdditiveState::Type> InCombatAdditiveState) {
}

void UBiped_AnimInstance::GetStationState_Implementation(TEnumAsByte<EStationState::Type>& OutState) {
}

void UBiped_AnimInstance::GetStationMode_Implementation(TEnumAsByte<EStationMode::Type>& OutMode) {
}

ERightArmState::Type UBiped_AnimInstance::GetRightArmState_Implementation(ERightArmPriority::Type InPriority) {
    return ERightArmState::None;
}

APickupTool* UBiped_AnimInstance::GetPickupTool_Implementation() {
    return NULL;
}

void UBiped_AnimInstance::GetPartialBodyState_Implementation(TEnumAsByte<EPartialBodyState::Type>& OutState) {
}

void UBiped_AnimInstance::GetParryStateNext_Implementation(TEnumAsByte<EParryState::Type>& OutState) {
}

void UBiped_AnimInstance::GetParryState_Implementation(TEnumAsByte<EParryState::Type>& OutState) {
}

int32 UBiped_AnimInstance::GetNumberOfAttackingActors() {
    return 0;
}

void UBiped_AnimInstance::GetMobilityStateLast_Implementation(TEnumAsByte<EMobilityState::Type>& OutState) {
}

void UBiped_AnimInstance::GetMobilityState_Implementation(TEnumAsByte<EMobilityState::Type>& OutState) {
}

ELeftArmState::Type UBiped_AnimInstance::GetLeftArmState_Implementation() {
    return ELeftArmState::None;
}

FInventoryResult UBiped_AnimInstance::GetInventoryResult_Implementation() {
    return FInventoryResult{};
}

EHeadTrackingState::Type UBiped_AnimInstance::GetHeadTrackingState_Implementation() {
    return EHeadTrackingState::None;
}

void UBiped_AnimInstance::GetHarvestState_Implementation(TEnumAsByte<EHarvestState::Type>& OutState) {
}

void UBiped_AnimInstance::GetFullBodyStateLast_Implementation(TEnumAsByte<EFullBodyState::Type>& OutState) {
}

void UBiped_AnimInstance::GetFullBodyState_Implementation(TEnumAsByte<EFullBodyState::Type>& OutState) {
}

AActor* UBiped_AnimInstance::GetFirstAttackingActorInStack() {
    return NULL;
}

AActor* UBiped_AnimInstance::GetFirstAttackingActor() {
    return NULL;
}

void UBiped_AnimInstance::GetDodgeState_Implementation(TEnumAsByte<EDodgeState::Type>& OutState) {
}

TEnumAsByte<EBasicMobilityMode::Type> UBiped_AnimInstance::GetDefaultBasicMobilityMode() {
    return EBasicMobilityMode::Normal;
}

TEnumAsByte<EBasicMobilityMode::Type> UBiped_AnimInstance::GetCurrentBasicMobilityMode() {
    return EBasicMobilityMode::Normal;
}

void UBiped_AnimInstance::GetAttackState_Implementation(TEnumAsByte<EAttackState::Type>& OutState) {
}

void UBiped_AnimInstance::GetAdditiveBodyState_Implementation(TEnumAsByte<EAdditiveBodyState::Type>& OutState) {
}

bool UBiped_AnimInstance::GetAbortAnim_Implementation() const {
    return false;
}

void UBiped_AnimInstance::Get_AimOffsetYaw_Implementation(float& OutYaw) {
}

void UBiped_AnimInstance::Get_AimOffsetPitch_Implementation(float& OutPitch) {
}

void UBiped_AnimInstance::FullyResetBasicMobilityMode() {
}

void UBiped_AnimInstance::FinishSettingCinematicRightArmState_Implementation(bool bBroadcastChange) {
}

void UBiped_AnimInstance::FinishSettingCinematicLeftArmState_Implementation(bool bBroadcastChange) {
}

void UBiped_AnimInstance::ComputeAditiveReactDirection_Implementation(AActor* InVictim, const FVector& InTraceDirection) {
}

UBiped_AnimInstance::UBiped_AnimInstance() {
    this->BlockedByWallState = ESBlockedByWallAnimState::None;
    this->OpenDoorState = EOpenDoorAnimState::LeftHand;
    this->AttackState = EAttackState::None;
    this->ParryState = EParryState::None;
    this->ParryStateNext = EParryState::None;
    this->DodgeState = EDodgeState::None;
    this->StationState = EStationState::None;
    this->StationMode = EStationMode::FullBody;
    this->FullBodyState = EFullBodyState::None;
    this->FullBodyStateLast = EFullBodyState::None;
    this->MobilityTypeState = EMobilityState::None;
    this->MobilityTypeStateLast = EMobilityState::None;
    this->HarvestState = EHarvestState::PullFail;
    this->PartialBodyState = EPartialBodyState::None;
    this->LeftArmActiveCinematicCount = 0;
    this->RightArmActiveCinematicCount = 0;
    this->AdditiveBodyState = EAdditiveBodyState::None;
    this->CombatAdditiveAbility = NULL;
    this->IsInAir = false;
    this->IsCrouching = false;
    this->InLockOnMode = false;
    this->AmpedPercent = 0.00f;
    this->InitialJumpAngle = 0.00f;
    this->PickupTool = NULL;
    this->PickupToolHeight = 0.00f;
    this->PutdownToolHeight = 0.00f;
    this->HoldingBucket = false;
    this->IsMultiHarvestPlot = false;
    this->UseAimOffset = 0;
    this->AimOffsetYaw = 0.00f;
    this->AimOffsetPitch = 0.00f;
    this->LastAimOffsetYaw = 0.00f;
    this->IsEquippingWand = false;
    this->IsWandEquipped = false;
    this->DoFullBodySpellIfInIdle = false;
    this->IsWandReady = false;
    this->bAdditiveTurnLeanActive = false;
    this->AdditiveLeanAngle = 0.00f;
    this->IsFlooUIFinished = false;
    this->IsFlooUICancelled = false;
    this->IsAdvanced = false;
    this->LoadFinished = false;
    this->TeleportFinished = false;
    this->BackAwayFromLedge = false;
    this->PlayBlockedByWallAnim = false;
    this->LeftEffectorLoc = 0.00f;
    this->RightEffectorLoc = 0.00f;
    this->HipsOffset = 0.00f;
    this->IsHoldingAttack = false;
    this->IsAbortingParry = false;
    this->IsAbortingAnim = false;
    this->bIsAnticipatingAttack = false;
    this->AnticipationAngle = 0.00f;
    this->ThrowDistance = 0.00f;
    this->AngleToDesiredDirection = 0.00f;
    this->bFromLightDirectional = false;
    this->IdleTimeStamp = 0.00f;
    this->CustomRootMotionMultiplier = 1.00f;
}

