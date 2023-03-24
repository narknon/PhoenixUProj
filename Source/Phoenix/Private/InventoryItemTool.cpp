#include "InventoryItemTool.h"
#include "Templates/SubclassOf.h"

class AActor;
class ACharacter;
class AMunitionType_Base;
class UInventoryItemToolRecord;

void AInventoryItemTool::UseItem_Implementation() {
}

void AInventoryItemTool::UnequipTool() {
}

void AInventoryItemTool::TimeOutTimerExpired() {
}

void AInventoryItemTool::StartUnequipTimer() {
}

AMunitionType_Base* AInventoryItemTool::SpawnMunition(TSubclassOf<AMunitionType_Base> MunitionClass, FVector SourceLocation) {
    return NULL;
}

void AInventoryItemTool::SpawnInventoryObject_Implementation(bool bFlag) {
}

void AInventoryItemTool::SetSpeedBasedOnDistance(AMunitionType_Base* Munition, float Time, float MinSpeed, float MaxSpeed) {
}

void AInventoryItemTool::OnItemConsumed_Implementation() {
}

void AInventoryItemTool::OnHidden_Implementation(bool bFlag) {
}

void AInventoryItemTool::OnDeactivate_Implementation() {
}

void AInventoryItemTool::OnCustomAnimation_Implementation() {
}

void AInventoryItemTool::OnActivate_Implementation() {
}

bool AInventoryItemTool::ItemHasCustomAnimation() {
    return false;
}

void AInventoryItemTool::ItemEvent_Implementation(FName EventName) {
}

TEnumAsByte<ELeftArmState::Type> AInventoryItemTool::GetLeftArmState(FName Mechanic) {
    return ELeftArmState::None;
}

UInventoryItemToolRecord* AInventoryItemTool::GetInventoryItemToolRecord() const {
    return NULL;
}

ACharacter* AInventoryItemTool::GetCharacter() const {
    return NULL;
}

void AInventoryItemTool::FullBodyItemUsageCompleted_Implementation() {
}

void AInventoryItemTool::EndItemUsage_Implementation() {
}

void AInventoryItemTool::EndItemSelection_Implementation() {
}

bool AInventoryItemTool::ConsumeItem() {
    return false;
}

FVector AInventoryItemTool::ComputeVelocityToTarget(AActor* ProjectileActor, float Time, float MinSpeed, float MaxSpeed) {
    return FVector{};
}

void AInventoryItemTool::CancelUnequipTimer() {
}

void AInventoryItemTool::BeginItemUsage_Implementation() {
}

AInventoryItemTool::AInventoryItemTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bTriggerAbilityOnConsume = false;
    this->UseItemAbility = NULL;
    this->EquipItemAbility = NULL;
    this->HoldItemAbility = NULL;
    this->HandOnlyItemAbility = NULL;
    this->LeftArmState = ELeftArmState::StopMotionOnly;
    this->RightArmState = ERightArmState::HideItem;
    this->HeadTrackingState = EHeadTrackingState::Disallow;
    this->bDisableRiderHandIK = false;
    this->MinUsageTime = 0.00f;
    this->MaxUsageTime = 0.00f;
    this->UnEquipTimer = 30.00f;
    this->bStartUnequipTimerOnConsume = true;
    this->bAllowUseWhenCountIsZero = false;
    this->bIgnoresTargets = false;
    this->bHideWhenDepleted = false;
    this->bUseItemOnEndSelection = false;
    this->bHasCustomAnimation = false;
}

