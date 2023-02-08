#include "Biped_Player.h"
#include "CustomizableCharacterComponent.h"
#include "ToolSetComponent.h"
#include "ConversationComponent.h"
#include "Templates/SubclassOf.h"
#include "VegetationInteractionComponentPlayer.h"

class AActor;
class ABiped_Player;
class AFieldGuideHotSpot;
class AStation;
class UAISense;
class UAkComponent;
class UBiped_AnimInstance;
class UCameraComponent;
class UCurveFloat;
class UInteractionArchitectAsset;
class UInventoryItemToolRecord;
class UObject;
class USpellToolRecord;
class UStickFlickWatcherRecord;

bool ABiped_Player::UseNewConversations() const {
    return false;
}

bool ABiped_Player::UseInventoryItemByName_Implementation(FName InventoryObjectID, FName HolderID) {
    return false;
}

void ABiped_Player::UseFinisherFocus() {
}

void ABiped_Player::UpdateFinsherAvailableFX() {
}

void ABiped_Player::UpdateDifficulty() {
}

void ABiped_Player::UpdateCamMove(float DeltaTime) {
}

bool ABiped_Player::ToadStatueTeleport(const AActor* InDestinationActor, const FVector InOffset) {
    return false;
}

void ABiped_Player::TargetSighted(UAISense* Sense, const AActor* Target) {
}

void ABiped_Player::TargetLost(UAISense* Sense, const AActor* OldTarget) {
}

void ABiped_Player::TargetChanged(UAISense* Sense, const AActor* NewTarget, const AActor* OldTarget) {
}

void ABiped_Player::SuspendStoryModeArmor(bool bFlag) {
}

bool ABiped_Player::StopPlayerInput() {
    return false;
}

void ABiped_Player::StopMove_Implementation() {
}

AActor* ABiped_Player::StartCriticalFinisher() {
    return NULL;
}

void ABiped_Player::StartBulletTime(float Dilation, float Duration, bool DoFixedCam, float PlayerDilation, float EaseInDuration, float EaseOutDuration) {
}

void ABiped_Player::SpawnRockSlide(UClass* InActorClass, float ProjectForward) {
}

void ABiped_Player::SpawnItemMountCallback(UInventoryItemToolRecord* InToolRecord) {
}

AActor* ABiped_Player::SpawnFaceTarget_Implementation(TSubclassOf<AActor> SpawnActorClass) {
    return NULL;
}

bool ABiped_Player::ShadowBlinkTeleport(const AActor* InBlinkTarget, const float InBlinkDistanceFromTarget, const bool bIsGate, const bool bIsStealth, FVector& OutBlinkLocation, FRotator& OutBlinkRotation) {
    return false;
}

void ABiped_Player::SetWandStyle(FName WandStyle) {
}

void ABiped_Player::SetWandBaseStyle(FName InWandBase) {
}

void ABiped_Player::SetUsingElderWand(bool bUsing) {
}

void ABiped_Player::SetStartingMovementTime(const float InStartingMovementTime) {
}

bool ABiped_Player::SetPlayerSocialHeritage(TEnumAsByte<SocialHeritageStatusIDs> NewHeritage) {
    return false;
}

bool ABiped_Player::SetPlayerGenderPronoun(EGenderPronoun NewGenderPronoun) {
    return false;
}

void ABiped_Player::SetPhoenixCameraRotation_Implementation(const FRotator& DesiredRotation) {
}

void ABiped_Player::SetPhoenixCameraLookAt_TimeBased_Implementation(const FVector& LookAtPoint, float LookAtTime) {
}

void ABiped_Player::SetPhoenixCameraLookAt_ActorAndTime_Implementation(AActor* LookAtActor, float LookAtTime) {
}

void ABiped_Player::SetPhoenixCameraLookAt_Actor_Implementation(AActor* LookAtActor, float ScaleSpeed) {
}

void ABiped_Player::SetPhoenixCameraLookAt_Implementation(const FVector& LookAtPoint, float ScaleSpeed) {
}

void ABiped_Player::SetOverrideWandStyle(FName WandStyle) {
}

void ABiped_Player::SetMotionListener(UAkComponent* AkComponent, bool PlayerOrientation) {
}

void ABiped_Player::SetManagedAM(float Value) {
}

void ABiped_Player::SetLastSafeInteractLocation(FVector Location) {
}

void ABiped_Player::SetLastEdgeState(EEdgeState::Type InEdgeState) {
}

void ABiped_Player::SetInvulnerableTime(float invulnerableTime) {
}

void ABiped_Player::SetInvulnerable(bool bInInvulnerable) {
}

void ABiped_Player::SetInteractStickyTarget(bool bSet) {
}

void ABiped_Player::SetInLockOnMode(const bool bInFlag) {
}

void ABiped_Player::SetHighlitActor(AActor* InHighlitActor) {
}

void ABiped_Player::SetFieldGuideHotSpot(AFieldGuideHotSpot* InFieldGuideHotSpot) {
}

void ABiped_Player::SetDodgeDirection() {
}

void ABiped_Player::SetDisableCombatPlantHideOnSuspendEnemies(bool bInVal) {
}

void ABiped_Player::SetCooldownRateScale(float RateScale) {
}

void ABiped_Player::SetCauseOfDeath(const ECharacterDeathType InCauseOfDeath) {
}

void ABiped_Player::SetCameraStyle(FName CameraStyle) {
}

void ABiped_Player::SetAutoTargetingDirection(FVector InWorldDirection) {
}

void ABiped_Player::SetAccessibilitySpellToggle(bool ToggleOn) {
}

AActor* ABiped_Player::Set_WandCast_TargetTrackerTargets(bool bIgnoreTargets, AActor* InTargetOverride, FVector InTargetOverrideWorldLocation) {
    return NULL;
}

void ABiped_Player::SendCriticalMunitionImpactToTarget(AActor* TargetActor, const FName UniqueTag, const TArray<UInteractionArchitectAsset*>& MunitionDataAssets, const FGameplayTagContainer& MunitionTagContainer, const float Damage) {
}

bool ABiped_Player::SafeTeleportTo(const FVector& DestLocation, const FRotator& DestRotation, bool bIsATest, bool bNoCheck) {
    return false;
}

bool ABiped_Player::RestorePlayerInput() {
    return false;
}

void ABiped_Player::RestoreHealth() {
}

void ABiped_Player::RestartComboTimeout() {
}

void ABiped_Player::ResetStickTime() {
}

void ABiped_Player::ResetPhoenixCameraRotation_Implementation(float ResetSpeed, UCurveFloat* ResetSpeedCurve) {
}

void ABiped_Player::ResetComboPoints() {
}

void ABiped_Player::ResetCloth() {
}

void ABiped_Player::RequestStick_Implementation(float StickX, float StickY) {
}

void ABiped_Player::RepairOrientation() {
}

void ABiped_Player::ReleasePhoenixCameraLookAt_Implementation() {
}

void ABiped_Player::RecordSafeLocation() {
}

void ABiped_Player::RecordSafeInteractLocation() {
}

bool ABiped_Player::QuickActionInteract_Implementation(int32 Index) {
    return false;
}

void ABiped_Player::PutPlayerIntoCinematicState(bool bFlag, bool bAlterAbilities) {
}

void ABiped_Player::PushDisableStack_Implementation(FName_GameLogicVarInt32 StackName) {
}

bool ABiped_Player::ProcessStick_Implementation(float StickX, float StickY, const float DeltaTime, const UCurveFloat* DeadZoneCurve, const UCurveFloat* SpeedCurve, const UCurveFloat* SpeedGovernorCurve, float& WorldSpeed, FVector& WorldDirection, ECustomInterpType::Type InterpType, float InterpSpeed, float StickMagReductionDelayTimer) {
    return false;
}

bool ABiped_Player::ProcessFollowTarget(AActor* InFollowActor, const UCurveFloat* SpeedCurve, float& OutWorldSpeed, FVector& OutWorldDirection) {
    return false;
}

void ABiped_Player::PopDisableStack_Implementation(FName_GameLogicVarInt32 StackName) {
}

void ABiped_Player::PlayerGetOutOfBed(AStation* BedStation, UClass* PlayerBedAbility) {
}

bool ABiped_Player::PlacePlayerInBed(AStation*& BedStation, UClass*& PlayerBedAbility) {
    return false;
}

bool ABiped_Player::PlaceOnGround(const float DownDistance) {
    return false;
}


void ABiped_Player::PauseComboTimeout() {
}

void ABiped_Player::OnSaveGameLoaded() {
}

void ABiped_Player::OnQuickItemSlotted(const UObject* InCaller, const FName& ItemName) {
}

void ABiped_Player::OnNewGame(const UObject* InCaller, const bool bInIsIntro) {
}

void ABiped_Player::OnCurtainRaised() {
}

void ABiped_Player::OnCharacterLoadComplete(AActor* Actor) {
}

void ABiped_Player::OnBlackboardInitialized(const bool bSuccess) {
}

void ABiped_Player::OnAboutToSaveGame() {
}

void ABiped_Player::OnAbilityAnimationBecameActive() {
}

void ABiped_Player::NotifySucessfulBlock() {
}

void ABiped_Player::NotifyDodgeFinished() {
}

void ABiped_Player::LockOnCamFlick_Implementation(UStickFlickWatcherRecord* InStickFlickWatcherRecord) {
}

void ABiped_Player::LockOnCameraMoving_Implementation(bool bFlag) {
}

bool ABiped_Player::LoadInventoryItemByName(FName InventoryObjectID, FName HolderID) {
    return false;
}

void ABiped_Player::LevelUp() {
}

void ABiped_Player::LEDDamageEffect(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit) {
}

void ABiped_Player::LeafNodeSwitched() {
}

bool ABiped_Player::IsVenomousTentaculaAtMax() {
    return false;
}

bool ABiped_Player::IsSwimming() {
    return false;
}

bool ABiped_Player::IsPlayingIntro() {
    return false;
}

bool ABiped_Player::IsPerfectRetaliate() const {
    return false;
}

bool ABiped_Player::IsManagedAMEnabled() {
    return false;
}

bool ABiped_Player::IsLockedOn_Implementation() {
    return false;
}

bool ABiped_Player::IsInventoryItemHighlighted() {
    return false;
}

bool ABiped_Player::IsInLockOnMode() {
    return false;
}

bool ABiped_Player::IsHoverDroneActive() {
    return false;
}

bool ABiped_Player::IsFinisherAvailable() {
    return false;
}

bool ABiped_Player::IsCrawling() {
    return false;
}

bool ABiped_Player::IsChompingCabbageAtMax() {
    return false;
}

bool ABiped_Player::IsCameraMoving() const {
    return false;
}

bool ABiped_Player::IsAMPushAvailable() {
    return false;
}

void ABiped_Player::InteractingWithActor(const AActor* InActor) {
}

bool ABiped_Player::InstaUseInventoryItem_Implementation() {
    return false;
}

bool ABiped_Player::InLockOnMode_Implementation() {
    return false;
}

bool ABiped_Player::InCombatModeDelayed() const {
    return false;
}

bool ABiped_Player::InCombatMode() const {
    return false;
}

bool ABiped_Player::IgnoreRetaliateTarget(AActor* RetaliateTarget) {
    return false;
}

void ABiped_Player::HighestEnemyChanged(AActor* InEnemyActor, int32 InLevelDiff) {
}

void ABiped_Player::HideReticle(bool bHide) {
}

bool ABiped_Player::HasMandrakeTalent() {
    return false;
}

void ABiped_Player::HandleVenomousTentaculaCountChanged() {
}

bool ABiped_Player::HandleDodgeUnblockable(AActor*& OutAttacker) {
    return false;
}

void ABiped_Player::HandleChompingCabbageCountChanged() {
}

void ABiped_Player::HandleActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

FName ABiped_Player::GetWandStyle() const {
    return NAME_None;
}

FName ABiped_Player::GetWandBaseStyle() const {
    return NAME_None;
}

int32 ABiped_Player::GetVenomousTentaculaMax() {
    return 0;
}

int32 ABiped_Player::GetVenomousTentaculaCount() {
    return 0;
}

ABiped_Player* ABiped_Player::GetTheBipedPlayer() {
    return NULL;
}

UCurveFloat* ABiped_Player::GetSpeedGovernorCurve_Implementation() {
    return NULL;
}

UCurveFloat* ABiped_Player::GetSpeedCurve_Implementation(bool& bIgnoreGovernor) {
    return NULL;
}

TEnumAsByte<SocialHeritageStatusIDs> ABiped_Player::GetPlayerSocialHeritage() {
    return SOCIAL_HERITAGE_STATUS_HALFBLOOD;
}

float ABiped_Player::GetPlayerMovementDuration() {
    return 0.0f;
}

float ABiped_Player::GetPlayerLastUsedItemEffectiveness() {
    return 0.0f;
}

EGenderPronoun ABiped_Player::GetPlayerGenderPronoun() {
    return EGenderPronoun::GENDER_WIZARD;
}

int32 ABiped_Player::GetPlantCount(const FString& trackerName) {
    return 0;
}

int32 ABiped_Player::GetOffenseStat() {
    return 0;
}

void ABiped_Player::GetMoveStickValues(float& X, float& Y) const {
}

UAkComponent* ABiped_Player::GetMotionListenerPlayerOrientation() {
    return NULL;
}

UAkComponent* ABiped_Player::GetMotionListenerCameraOrientation() {
    return NULL;
}

float ABiped_Player::GetMaxFocus() const {
    return 0.0f;
}

FVector ABiped_Player::GetLastSafeLocation() {
    return FVector{};
}

FVector ABiped_Player::GetLastSafeInteractLocation() {
    return FVector{};
}

bool ABiped_Player::GetIsOnAMountOrInTransition() const {
    return false;
}

int32 ABiped_Player::GetInventorySizeModification() {
    return 0;
}

float ABiped_Player::GetHiddenAfterTakedownTime() {
    return 0.0f;
}

bool ABiped_Player::GetGameLogicBoolVariable(FName_GameLogicVarBool BoolVar) {
    return false;
}

float ABiped_Player::GetFocusPercent() {
    return 0.0f;
}

float ABiped_Player::GetFocus() const {
    return 0.0f;
}

float ABiped_Player::GetFinisherDamage() const {
    return 0.0f;
}

float ABiped_Player::GetExpectedDistanceFromTarget(bool bIgnoreTargets, AActor* InTargetOverride, bool& bFound, FVector& ToTarget) {
    return 0.0f;
}

int32 ABiped_Player::GetDefenseStat() {
    return 0;
}

float ABiped_Player::GetCurrentCriticalHealthFadeOutPercent() const {
    return 0.0f;
}

int32 ABiped_Player::GetCooldownStat() {
    return 0;
}

float ABiped_Player::GetCooldownRateScale() const {
    return 0.0f;
}

float ABiped_Player::GetCooldownPercentByName(FName SpellName) {
    return 0.0f;
}

float ABiped_Player::GetCooldownPercent(USpellToolRecord* InSpellToolRecord) {
    return 0.0f;
}

int32 ABiped_Player::GetConsecutiveEnemyHits() const {
    return 0;
}

float ABiped_Player::GetCompanionsAtMaxLevel() const {
    return 0.0f;
}

float ABiped_Player::GetComboPoints() const {
    return 0.0f;
}

int32 ABiped_Player::GetChompingCabbageMax() {
    return 0;
}

int32 ABiped_Player::GetChompingCabbageCount() {
    return 0;
}

ECharacterDeathType ABiped_Player::GetCauseOfDeath() {
    return ECharacterDeathType::Default;
}

int32 ABiped_Player::GetBonusSpellLoadouts() {
    return 0;
}

int32 ABiped_Player::GetBonusAncientMagicBars() {
    return 0;
}

UBiped_AnimInstance* ABiped_Player::GetBipedAnimInstance() const {
    return NULL;
}

FVector ABiped_Player::GetBestLockOnActor_WorldLocation_Implementation() {
    return FVector{};
}

FVector ABiped_Player::GetBestLockOnActor_ScreenLocation_Implementation() {
    return FVector{};
}

FVector ABiped_Player::GetBestAutoTargetActor_WorldLocation_Implementation() {
    return FVector{};
}

float ABiped_Player::GetBaseOffenseStat() const {
    return 0.0f;
}

float ABiped_Player::GetBaseDefenseStat() const {
    return 0.0f;
}

float ABiped_Player::GetBaseCooldownStat() const {
    return 0.0f;
}

bool ABiped_Player::GetAccessibilitySpellToggle() const {
    return false;
}

void ABiped_Player::FullyResetPhoenixCamera_Implementation(float ResetSpeed, UCurveFloat* ResetSpeedCurve) {
}

void ABiped_Player::ForceEndDisillusionment() {
}

void ABiped_Player::EndCriticalFinisher(AActor* InTargetActor) {
}

void ABiped_Player::EndBulletTime(float EaseOutDuration) {
}

void ABiped_Player::EnableManagedAM(bool Enabled) {
}

void ABiped_Player::DisablePlayerHealthRecovery(bool bDisable) {
}

void ABiped_Player::DisableCooldownPickups(bool bDisable) {
}

void ABiped_Player::DetectEdgeChange(FVector TestActorLocation, float TraceRadius, bool bSendEvents, bool bDebugDraw) {
}

void ABiped_Player::DEBUG_SetGlobalTimeDilation(const UObject* WorldContextObject, float TimeDilation) {
}

void ABiped_Player::DamageDirectionEffect(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit) {
}

bool ABiped_Player::CreateLinkToAttackingActor(const EEnemy_ParryButtonPressed ParryEventReason, bool& bOutDodgeWindow) {
    return false;
}

void ABiped_Player::ComputeAimOffset(const FName BoneName, float& Pitch, float& Yaw) {
}

void ABiped_Player::CognitionTargetPlayerAwareStateChanged(ENPC_TargetAwareState InAwareState) {
}

void ABiped_Player::CognitionTargetHealthChanged(AActor* Target, float InHealthChanged, bool bIndicateHUD) {
}

void ABiped_Player::ClearStick_Implementation() {
}

void ABiped_Player::ClearOverrideWandStyle() {
}

void ABiped_Player::ClearInvulnerable() {
}

void ABiped_Player::ClearCustomCameras() {
}

void ABiped_Player::ChangeManagedAM(float change) {
}

void ABiped_Player::CameraStickLastMovedChanged(bool InCameraStickMoved) {
}

float ABiped_Player::CalculateVendorPricesModifier(const FVendorTransactionInfo& Info) {
    return 0.0f;
}

float ABiped_Player::CalculateStealRateModifier() {
    return 0.0f;
}

float ABiped_Player::CalculateSneakOScopeWindupModifier() {
    return 0.0f;
}

float ABiped_Player::CalculateSilencioRangeModifier() {
    return 0.0f;
}

float ABiped_Player::CalculatePlantDamageModifier(FName DbId) {
    return 0.0f;
}

float ABiped_Player::CalculateMandrakeBonusReaction() {
    return 0.0f;
}

FVector ABiped_Player::CalculateLookAtDirection_Implementation() {
    return FVector{};
}

int32 ABiped_Player::CalculateExtendedCompanionInventoryCapacity() {
    return 0;
}

bool ABiped_Player::AutoNavToTarget(AActor* InTarget, const float InSpeed, const float DistanceFromTarget) {
    return false;
}

bool ABiped_Player::AllowStop(const float InWorldSpeed, const FVector InWorldDirection, float DeltaTime, float MinTime) {
    return false;
}

bool ABiped_Player::AllowMove(const float InWorldSpeed, const FVector InWorldDirection, float DeltaTime, float MinTime) {
    return false;
}

void ABiped_Player::AdjustFocusByName(FName Name, float ExternalFocusModifier) {
}

void ABiped_Player::AdjustFocus(float change, float ExternalFocusModifier) {
}

void ABiped_Player::AdjustCooldownsByCategory(float Time, ESpellCategory SpellCategory) {
}

void ABiped_Player::AdjustCooldown(FName SpellName, float Time, bool AddIfNoneExists) {
}

void ABiped_Player::AdjustComboPoints(EComboType ComboType, AActor* Target) {
}

void ABiped_Player::AddCustomCamera(UCameraComponent* customCam, float weight) {
}

ABiped_Player::ABiped_Player() {
    this->ConversationComponent = CreateDefaultSubobject<UConversationComponent>(TEXT("ConversationComponent"));
    this->Customization = CreateDefaultSubobject<UCustomizableCharacterComponent>(TEXT("Customization"));
    this->PlayerSocialReasoning = NULL;
    this->InventoryToolSetComponent = CreateDefaultSubobject<UToolSetComponent>(TEXT("InventoryToolSetComponent"));
    this->bAllowFastWalk = false;
    this->WalkSlowModeSpeedCurve = NULL;
    this->WalkModeSpeedCurve = NULL;
    this->WalkOnlyModeSpeedCurve = NULL;
    this->WalkFastModeSpeedCurve = NULL;
    this->WalkFastOnlyModeSpeedCurve = NULL;
    this->JogModeSpeedCurve = NULL;
    this->JogOnlyModeSpeedCurve = NULL;
    this->SprintModeSpeedCurve = NULL;
    this->JogModeSpeedGovernorCurve = NULL;
    this->GryffindorMaleBedAbility = NULL;
    this->GryffindorFemaleBedAbility = NULL;
    this->RavenClawMaleBedAbility = NULL;
    this->RavenClawFemaleBedAbility = NULL;
    this->HufflePuffMaleBedAbility = NULL;
    this->HufflePuffFemaleBedAbility = NULL;
    this->SlytherinMaleBedAbility = NULL;
    this->SlytherinFemaleBedAbility = NULL;
    this->AttackIndicatorActorClass = NULL;
    this->AttackIndicatorActor = NULL;
    this->InnerDeadZoneMin = 0.20f;
    this->InnerDeadZoneMax = 0.40f;
    this->OuterDeadZone = 0.75f;
    this->EdgeState = EEdgeState::None;
    this->EdgeDistanceToGround = 0.00f;
    this->EdgeDistanceFromEdge = 0.00f;
    this->SyncToSplineComponent = NULL;
    this->SyncToSplineDirection = 1.00f;
    this->SyncToSplineDistance = 0.00f;
    this->DefaultIdleAbility = NULL;
    this->MaxChompingCabbage = 3;
    this->MaxVenomousTentacula = 2;
    this->AllowPlayerCamContorlOnOtherActorCam = false;
    this->InvertCameraPitchControl = false;
    this->InvertCameraYawControl = false;
    this->InvertMoveLeftRightControl = false;
    this->InvertMoveForwardBackControl = false;
    this->EnableFadeSystem = true;
    this->PlayerInThisFieldGuideHotSpot = NULL;
    this->FinisherDamage = 250.00f;
    this->ElderWandFinisherDamage = 375.00f;
    this->MaxFocus = 1000.00f;
    this->InitialNumBarsFilled = 2;
    this->FinisherFocusCost = 1000.00f;
    this->ManagedFinisherFocusCost = 1000.00f;
    this->PushFocusCost = 20.00f;
    this->ComboResetTime = 10.00f;
    this->AdditionalComboResetTimeOnParry = 1.00f;
    this->CooldownPickupFirstTierSize = 10;
    this->CooldownPickupTierSize = 10;
    this->ExtendedCombatTime = 3.00f;
    this->HealthIncreasePerLevel = 2.00f;
    this->LeftFootSocketName = TEXT("LeftFootSocket");
    this->RightFootSocketName = TEXT("RightFootSocket");
    this->LeftStickMagWalkingCurve = NULL;
    this->LeftStickMagJoggingCurve = NULL;
    this->BulletTimeStartSeconds = 1.00f;
    this->BulletTimeDilationCurve = NULL;
    this->BulletTimeDurationSeconds = 2.00f;
    this->BulletTimeDialation = 0.10f;
    this->CutBackToPlayerCamAfterTimeDialationSec = 3.00f;
    this->DamageEffectMaterialInstance = NULL;
    this->DamageEffectCurve = NULL;
    this->DamageEffectDuration = 0.20f;
    this->DamageEffectScale = 1.00f;
    this->CriticalHealthPulseTimeCurve = NULL;
    this->CriticalHealthFadeOutTime = 3.00f;
    this->DamageDirectionClass = NULL;
    this->PercentHealthRecoverdPerSecond = 1.00f;
    this->SecondsAfterCombatBeforeRecoveryStarts = 5.00f;
    this->DoDamageOnNextLanding = false;
    this->UseDodgeCamera = false;
    this->InHoverDrone = false;
    this->bLookAtHips = false;
    this->cameraOffsetScale = 1.00f;
    this->bLockOutPlayerCamControl = false;
    this->bLockOutPlayerCamControlPitch = false;
    this->bAllowEdgeCheck = true;
    this->bInCombatMode = false;
    this->bInCombatModeDelayed = false;
    this->FollowActor = NULL;
    this->CautiousMode = 0;
    this->InStealthMode = false;
    this->bIsInvisible = false;
    this->InCinematic = false;
    this->WandLinkResult = EWandLinkResult::NonLethalGetup;
    this->bHoldingProtegoParry = false;
    this->EnemyDetectionFXClass = NULL;
    this->EnemyDetectionSFX = NULL;
    this->EnemyAlertSFX = NULL;
    this->EnemyAggroSFX = NULL;
    this->bUseDesiredFocusDirection = false;
    this->VegetationInteraction = CreateDefaultSubobject<UVegetationInteractionComponentPlayer>(TEXT("VegetationInteraction"));
    this->LastCriticalFinisher = NULL;
    this->TimeoutLookAtCameraDirection = 3.00f;
    this->MotionListenerCameraOrientation = NULL;
    this->MotionListenerPlayerOrientation = NULL;
    this->DamageDirectionActor = NULL;
}

