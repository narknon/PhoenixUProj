#include "Biped_Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AnimationComponent.h"
#include "FacialComponent.h"
#include "BTCustomComponent.h"
#include "CognitionStimuliSourceComponent.h"
#include "ContextFilterComponent.h"
#include "ToolSetComponent.h"
#include "BipedStateComponent.h"

class AActor;
class APickupTool;
class ATool;
class AWandTool;
class UObject;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USpellToolRecord;

void ABiped_Character::ZeroKinematicIntegratorLinearVelocity() {
}

void ABiped_Character::ZeroKinematicIntegratorAngularVelocity() {
}

void ABiped_Character::UnEquipWand_Implementation() {
}

void ABiped_Character::StartCrouching(const UObject* Provider, TEnumAsByte<ETargetSpeedMode::Type> SpeedMode, TEnumAsByte<ETargetSpeedMode::Type> SpeedModifier) {
}

void ABiped_Character::StairsStateHasChanged(TEnumAsByte<EStairsState::Type> InLastStairsState, TEnumAsByte<EStairsState::Type> InNewStairsState) {
}

void ABiped_Character::SetTargetDirection(FVector i_targetDirection) {
}

void ABiped_Character::SetTargetDestination(FVector i_targetDestination) {
}

void ABiped_Character::SetTargetComponent(UPrimitiveComponent* i_pTargetComponent) {
}

void ABiped_Character::SetTargetBoneName(FName i_targetBoneName) {
}

void ABiped_Character::SetSpellCastHandle_Implementation(int32 InSpellCastHandle) {
}

void ABiped_Character::SetSpell(int32 Group, int32 Index, USpellToolRecord* Spell) {
}

void ABiped_Character::SetRightArmState_Implementation(ERightArmState::Type InState, ERightArmPriority::Type InPriority, bool bBroadcastChange) {
}

void ABiped_Character::SetRayCastActor(AActor* i_pRayCastActor) {
}

void ABiped_Character::SetPickupTool_Implementation(APickupTool* InPickupTool) {
}

void ABiped_Character::SetPartialBodyState_Implementation(const TEnumAsByte<EPartialBodyState::Type>& InState) {
}

void ABiped_Character::SetParryState_Implementation(const TEnumAsByte<EParryState::Type>& InState) {
}

void ABiped_Character::SetFullBodyStateLast_Implementation(const TEnumAsByte<EFullBodyState::Type>& InState) {
}

void ABiped_Character::SetFullBodyState_Implementation(const TEnumAsByte<EFullBodyState::Type>& InState) {
}

void ABiped_Character::SetFinisherOptimalRatio_Implementation(const float OptimalRatio, EDynamicForceFeedbackAction::Type FeedbackAction) {
}

void ABiped_Character::SetFinisher(int32 Index, USpellToolRecord* Spell) {
}

void ABiped_Character::SetCombatReadyMode(const bool Flag) {
}

void ABiped_Character::SetAdditiveBodyState_Implementation(const TEnumAsByte<EAdditiveBodyState::Type>& InState) {
}

FName ABiped_Character::ParkourJump_Implementation(FName DefaultNode) {
    return NAME_None;
}

void ABiped_Character::OnHoverDroneControlModeChanged(TEnumAsByte<EHoverDroneControlMode::Type> NewMode) {
}

void ABiped_Character::OnEquippedChanged(ATool* ActivatedTool, ATool* DeactivatedTool) {
}

void ABiped_Character::Landed(const FHitResult& Hit) {
}

bool ABiped_Character::IsWandEquipped() {
    return false;
}

bool ABiped_Character::IsDead_Implementation() {
    return false;
}

bool ABiped_Character::IsCurrentLedgeAnOverhang() const {
    return false;
}

bool ABiped_Character::IsBlockedByWall() {
    return false;
}

AWandTool* ABiped_Character::GetWand_Implementation() const {
    return NULL;
}

FVector ABiped_Character::GetToTargetDirection_Implementation() {
    return FVector{};
}

FVector ABiped_Character::GetTargetDirection_Implementation() {
    return FVector{};
}

FVector ABiped_Character::GetTargetDestination_Implementation() const {
    return FVector{};
}

UPrimitiveComponent* ABiped_Character::GetTargetComponent_Implementation() {
    return NULL;
}

FName ABiped_Character::GetTargetBoneName_Implementation() {
    return NAME_None;
}

bool ABiped_Character::GetSpellsByGroup(int32 Group, TArray<USpellToolRecord*>& ToolRecordArray) {
    return false;
}

void ABiped_Character::GetSpellCastHandle_Implementation(int32& OutSpellCastHandle) {
}

USkeletalMeshComponent* ABiped_Character::GetSkeletalMesh_Implementation() const {
    return NULL;
}

ERightArmState::Type ABiped_Character::GetRightArmState_Implementation(ERightArmPriority::Type InPriority) {
    return ERightArmState::None;
}

AActor* ABiped_Character::GetRayCastActor() {
    return NULL;
}

float ABiped_Character::GetPutdownToolHeight_Implementation() {
    return 0.0f;
}

float ABiped_Character::GetPickupToolHeight_Implementation() {
    return 0.0f;
}

APickupTool* ABiped_Character::GetPickupTool_Implementation() {
    return NULL;
}

void ABiped_Character::GetPartialBodyState_Implementation(TEnumAsByte<EPartialBodyState::Type>& OutState) {
}

void ABiped_Character::GetParryState_Implementation(TEnumAsByte<EParryState::Type>& OutState) {
}

FTransform ABiped_Character::GetOriginalLedgeTransform() const {
    return FTransform{};
}

AActor* ABiped_Character::GetLockedOnActor_Implementation() {
    return NULL;
}

FInventoryResult ABiped_Character::GetInventoryResult_Implementation() {
    return FInventoryResult{};
}

AActor* ABiped_Character::GetHighlitActor_Implementation() {
    return NULL;
}

float ABiped_Character::GetHealth() {
    return 0.0f;
}

void ABiped_Character::GetFullBodyStateLast_Implementation(TEnumAsByte<EFullBodyState::Type>& OutState) {
}

void ABiped_Character::GetFullBodyState_Implementation(TEnumAsByte<EFullBodyState::Type>& OutState) {
}

bool ABiped_Character::GetFinishers(TArray<USpellToolRecord*>& ToolRecordArray) {
    return false;
}

FName ABiped_Character::GetCharacterID() const {
    return NAME_None;
}

AActor* ABiped_Character::GetBestLockOnActor_Implementation() {
    return NULL;
}

AActor* ABiped_Character::GetBestAutoTargetActor_Implementation() {
    return NULL;
}

FVector ABiped_Character::GetAutoTargetUpDirection_Implementation() {
    return FVector{};
}

FVector ABiped_Character::GetAutoTargetFocusDirection_Implementation() {
    return FVector{};
}

void ABiped_Character::GetAdditiveBodyState_Implementation(TEnumAsByte<EAdditiveBodyState::Type>& OutState) {
}

void ABiped_Character::FinishCrouching(const UObject* Provider) {
}

void ABiped_Character::FacingTargetsListIsNowEmpty(TEnumAsByte<ETargetType::Type> LastTargetType, TEnumAsByte<ETargetID::Type> LastTargetID) {
}

void ABiped_Character::FacingNotifyOfNewBestTarget(TEnumAsByte<ETargetType::Type> NewTargetType, TEnumAsByte<ETargetID::Type> NewTargetID) {
}

void ABiped_Character::EquipWand_Implementation() {
}

void ABiped_Character::EnablePawnInteraction(const bool bEnable) {
}

bool ABiped_Character::DetectFallIntoWater() {
    return false;
}

bool ABiped_Character::DetectDiveIntoWater() {
    return false;
}

void ABiped_Character::ComputeAttack_Implementation(AActor*& TargetActor) {
}

float ABiped_Character::ComputeAngleToDesiredDirection_Implementation() {
    return 0.0f;
}

void ABiped_Character::ClimbLedgeStart() {
}

void ABiped_Character::ClimbLedgeEnd() {
}

void ABiped_Character::CleanUpFinisherSpell() {
}

bool ABiped_Character::CanLandOnLedge() const {
    return false;
}

void ABiped_Character::CancelCurrentSpell(bool RemoveDisillusionment) const {
}

void ABiped_Character::CalculateLedgePullUpState(TEnumAsByte<EClimbingLedgeState::Type>& OutState, TEnumAsByte<EJumpingType::Type>& OutType) {
}

void ABiped_Character::CalculateClimbingLedgeState_Implementation(TEnumAsByte<EClimbingLedgeState::Type>& OutState, TEnumAsByte<EJumpingType::Type>& OutType) {
}

bool ABiped_Character::AdjustHealth(float change, bool bDontKill) {
    return false;
}

ABiped_Character::ABiped_Character() {
    this->ToolSetComponent = CreateDefaultSubobject<UToolSetComponent>(TEXT("ToolSetComponent"));
    this->CognitionStimuliSourceComponent = CreateDefaultSubobject<UCognitionStimuliSourceComponent>(TEXT("CognitionStimuliSourceComponent"));
    this->BehaviorComp_Primary = CreateDefaultSubobject<UBTCustomComponent>(TEXT("BehaviorCompPrimary"));
    this->BehaviorComp_Secondary = CreateDefaultSubobject<UBTCustomComponent>(TEXT("BehaviorCompSecondary"));
    this->BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
    this->ObjectStateComponent = CreateDefaultSubobject<UBipedStateComponent>(TEXT("BipedStateComponent"));
    this->ContextFilterComponent = CreateDefaultSubobject<UContextFilterComponent>(TEXT("ContextFilterComponent"));
    this->RPGAbilityComponent = NULL;
    this->FacialComponent = CreateDefaultSubobject<UFacialComponent>(TEXT("FacialComponent"));
    this->AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
    this->MAX_HEIGHT_FOR_CLIMB = 175.00f;
    this->MAX_HEIGHT_FOR_HANG = 100.00f;
    this->MAX_HEIGHT_FOR_JUMPWAIST = 0.00f;
    this->ledgeActor = NULL;
    this->CrouchCapsuleHalfHeight = 50.00f;
    this->CrouchCapsuleRadius = 50.00f;
    this->CrouchStartCapsuleBlendDuration = 0.30f;
    this->CrouchEndCapsuleBlendDuration = 0.30f;
    this->ParryState = EParryState::None;
    this->SpellCastHandle = 0;
    this->bIgnoreFallDamage = false;
    this->MaxAirHeight = -1000000.00f;
    this->LastGroundHeight = 0.00f;
    this->m_studentActorClassM = NULL;
    this->m_studentActorClassF = NULL;
}

