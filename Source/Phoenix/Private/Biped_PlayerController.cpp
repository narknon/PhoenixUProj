#include "Biped_PlayerController.h"
#include "CognitionComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class AAmbulatory_Character;
class UAISense;
class UAISense_CogGroup;
class UAISense_CogGroup_Aim;
class UAISense_CogGroup_AutoTarget;
class UAISense_CogGroup_Climb;
class UAISense_CogGroup_Interact;
class UAISense_CogGroup_Station;
class UAISense_CogGroup_TargetOfInterest;
class UCogGroupFocusDirection;
class UCogGroupPerceiverPoint;
class UCogGroupUpDirection;
class UCurveFloat;
class UObject;
class UPlayerInput;

void ABiped_PlayerController::TutorialAutoTargetBitChanged(bool bNewValue) {
}

void ABiped_PlayerController::TargetSighted(UAISense* Sense, const AActor* Target) {
}

void ABiped_PlayerController::TargetLost(UAISense* Sense, const AActor* OldTarget) {
}

void ABiped_PlayerController::TargetChanged(UAISense* Sense, const AActor* NewTarget, const AActor* OldTarget) {
}

void ABiped_PlayerController::StickClick(bool bOnlyOn, bool bOnlyOff) {
}

void ABiped_PlayerController::StartSettingSpecialAutoTarget(AActor* InSpecialActor, const UObject* Provider) {
}

void ABiped_PlayerController::StartSettingAutoTargetAlwaysTargetActor(AActor* InTargetActor, const UObject* Provider) {
}

void ABiped_PlayerController::StartAimModeTimeDilation(const float Dilation, const float EaseIn) {
}

void ABiped_PlayerController::SetTargetingMode(const TEnumAsByte<ETargetingMode::Type> InMode, bool bLockOnInAimMode) {
}

void ABiped_PlayerController::SetSpecialAutoTarget(AActor* InSpecialActor) const {
}

void ABiped_PlayerController::SetSenseEnabled(UAISense_CogGroup* InSense, bool bInFlag, bool bInForce) {
}

void ABiped_PlayerController::SetOppugnoAlwaysTargetActor(AActor* InActor) {
}

void ABiped_PlayerController::SetInteractStickyTarget(bool bSet) {
}

void ABiped_PlayerController::SetCameraRotation(const FRotator& DesiredRotation) {
}

void ABiped_PlayerController::SetCameraLookAt_TimeBased(const FVector& LookAtPoint, float LookAtTime) {
}

void ABiped_PlayerController::SetCameraLookAt_ActorAndTime(AActor* LookAtActor, float LookAtTime) {
}

void ABiped_PlayerController::SetCameraLookAt_Actor(AActor* LookAtActor, float SpeedScalar) {
}

void ABiped_PlayerController::SetCameraLookAt(const FVector& LookAtPoint, float SpeedScalar) {
}

void ABiped_PlayerController::SetAutoTargetAlwaysTargetActor(AActor* InActor) {
}

void ABiped_PlayerController::ResetCameraRotation(float ResetSpeed, UCurveFloat* ResetSpeedCurve) {
}

void ABiped_PlayerController::ReleaseLockFromTarget(ELockOnReticleType InLockOnType) {
}

void ABiped_PlayerController::ReleaseCameraLookAt() {
}

void ABiped_PlayerController::PawnTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated) {
}

void ABiped_PlayerController::OnInteractTargetRegistered(AActor* InTarget) {
}

void ABiped_PlayerController::OnCurtainLowered() {
}

void ABiped_PlayerController::MaxSpeedChanged(float InSpeed) {
}

void ABiped_PlayerController::LockOntoAutoTargetActor(ELockOnReticleType InLockOnType, AActor* AutoTargetActor) {
}

void ABiped_PlayerController::IsTargetCritical(AActor* Target) {
}

bool ABiped_PlayerController::IsSenseEnabled(UAISense_CogGroup* InSense) {
    return false;
}

bool ABiped_PlayerController::IsPlayerInAnimagusForm(UObject* WorldContextObject) {
    return false;
}

bool ABiped_PlayerController::IsLockedOntoTarget() {
    return false;
}

bool ABiped_PlayerController::IsActorInBestList(TSubclassOf<UAISense> SenseClass, const AActor* TestActor) {
    return false;
}

void ABiped_PlayerController::HermesBindForcedConversation(ABiped_PlayerController::FHermesOnForcedConversationDelegate Delegate_OnForcedConversation, const UObject* InOwner, FHermesBPDelegateHandle& Handle) {
}

UAISense_CogGroup_TargetOfInterest* ABiped_PlayerController::GetTargetOfInterestSense() {
    return NULL;
}

UAISense_CogGroup_Station* ABiped_PlayerController::GetStationInteractSense() {
    return NULL;
}

UPlayerInput* ABiped_PlayerController::GetPlayerInput() const {
    return NULL;
}

AActor* ABiped_PlayerController::GetOppugnoAlwaysTargetActor() {
    return NULL;
}

AActor* ABiped_PlayerController::GetLockedOnActor() {
    return NULL;
}

bool ABiped_PlayerController::GetLastValidMountLocation(FVector& OutLocation) const {
    return false;
}

FRotator ABiped_PlayerController::GetLastControlRotation() {
    return FRotator{};
}

UAISense_CogGroup_Interact* ABiped_PlayerController::GetInteractSense() {
    return NULL;
}

UAISense_CogGroup_Climb* ABiped_PlayerController::GetClimbSense() {
    return NULL;
}

AActor* ABiped_PlayerController::GetBestReparoActor() const {
    return NULL;
}

AActor* ABiped_PlayerController::GetBestOppugnoActor() const {
    return NULL;
}

AActor* ABiped_PlayerController::GetBestLockOnActor() const {
    return NULL;
}

FVector ABiped_PlayerController::GetBestAutoTargetActor_WorldLocation() const {
    return FVector{};
}

AActor* ABiped_PlayerController::GetBestAutoTargetActor() const {
    return NULL;
}

UAISense_CogGroup_AutoTarget* ABiped_PlayerController::GetAutoTargetSense() {
    return NULL;
}

UAISense_CogGroup_Aim* ABiped_PlayerController::GetAimSense() {
    return NULL;
}

float ABiped_PlayerController::GetAimBlendParameter() {
    return 0.0f;
}

void ABiped_PlayerController::FullyResetCamera(float ResetSpeed, UCurveFloat* ResetSpeedCurve) {
}

void ABiped_PlayerController::FlushInputKeys() {
}

bool ABiped_PlayerController::FlickToTarget(FVector2D StickFlickDirection) {
    return false;
}

void ABiped_PlayerController::FinishSettingSpecialAutoTarget(const UObject* Provider) {
}

void ABiped_PlayerController::FinishSettingAutoTargetAlwaysTargetActor(const UObject* Provider) {
}

void ABiped_PlayerController::FinishAimModeTimeDilation(const float EaseOut) {
}

void ABiped_PlayerController::ClearOppugnoAlwaysTargetActor() {
}

void ABiped_PlayerController::ClearAutoTargetAlwaysTargetActor() {
}

void ABiped_PlayerController::CanStickReset(bool& bCanReset) {
}

void ABiped_PlayerController::AutoTarget_UseShadowBlinkEval() {
}

void ABiped_PlayerController::AutoTarget_UseDefaultUpDirectionClass() {
}

void ABiped_PlayerController::AutoTarget_UseDefaultPerceiverPointClass() {
}

void ABiped_PlayerController::AutoTarget_UseDefaultFocusDirectionClass() {
}

void ABiped_PlayerController::AutoTarget_UseDefaultEval() {
}

void ABiped_PlayerController::AutoTarget_SetUpDirectionClass(UCogGroupUpDirection* InUpDirectionClass) {
}

void ABiped_PlayerController::AutoTarget_SetPerceiverPointClass(UCogGroupPerceiverPoint* InPerceiverPointClass) {
}

void ABiped_PlayerController::AutoTarget_SetFocusDirectionClass(UCogGroupFocusDirection* InFocusDirectionClass) {
}

void ABiped_PlayerController::AllowLockOn(bool bFlag) {
}

void ABiped_PlayerController::ActivateReparoSense(bool bFlag, bool bForce) {
}

void ABiped_PlayerController::ActivateOppugnoSense(bool bFlag, bool bForce) {
}

void ABiped_PlayerController::ActivateInteractSense(bool bFlag, bool bForce) {
}

void ABiped_PlayerController::ActivateClimbSense(bool bFlag, bool bForce) {
}

void ABiped_PlayerController::ActivateAutoTargetSense(bool bFlag, bool bForce) {
}

ABiped_PlayerController::ABiped_PlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UseAutoTargetCameraModes = false;
    this->AimModeFarDistanceRadius = 110.00f;
    this->AimModeNarrowRadius = 5.00f;
    this->TargetingMode = ETargetingMode::AutoTarget;
    this->CognitionComponent = CreateDefaultSubobject<UCognitionComponent>(TEXT("CognitionComponent"));
    this->SenseForAutoTargeting = NULL;
    this->LockOnReticleActorClass = NULL;
    this->LockOnReticleActor = NULL;
    this->LockOnReticleLookAtSpeedScalar = 10.00f;
    this->bAllowLockOn = true;
    this->OppugnoIndicatorClass = NULL;
    this->OppugnoIndicatorActor = NULL;
    this->bTargetingCameraAllowed = true;
    this->AutoTargetDistance = 80.00f;
    this->ReticuleVerticalScreenPosition = 0.50f;
    this->DoingAutoTargeting = false;
    this->bNearInteractable = false;
    this->CurrentInteractTarget = NULL;
    this->InteractionRange = 300.00f;
}

