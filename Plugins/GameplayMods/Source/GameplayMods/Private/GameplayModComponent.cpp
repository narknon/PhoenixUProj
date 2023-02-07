#include "GameplayModComponent.h"
#include "Net/UnrealNetwork.h"

class UGameplayPropertyMod;
class UGameplayPropertyModGroup;
class UObject;

void UGameplayModComponent::SetModBlackboardValue(const FGameplayTag& Tag, float Value, bool bForceRecomputeProperties) {
}

void UGameplayModComponent::ServerRemoveMod_Implementation(const UGameplayPropertyMod* InMod) {
}
bool UGameplayModComponent::ServerRemoveMod_Validate(const UGameplayPropertyMod* InMod) {
    return true;
}

void UGameplayModComponent::ServerRemoveGroup_Implementation(const UGameplayPropertyModGroup* InModGroup) {
}
bool UGameplayModComponent::ServerRemoveGroup_Validate(const UGameplayPropertyModGroup* InModGroup) {
    return true;
}

void UGameplayModComponent::ServerAddMod_Implementation(const UGameplayPropertyMod* InMod) {
}
bool UGameplayModComponent::ServerAddMod_Validate(const UGameplayPropertyMod* InMod) {
    return true;
}

void UGameplayModComponent::ServerAddGroup_Implementation(const UGameplayPropertyModGroup* InModGroup) {
}
bool UGameplayModComponent::ServerAddGroup_Validate(const UGameplayPropertyModGroup* InModGroup) {
    return true;
}

void UGameplayModComponent::RemoveTargetModdable(UObject* InTarget) {
}

void UGameplayModComponent::RemoveModReplicated(const UGameplayPropertyMod* InMod) {
}

void UGameplayModComponent::RemoveMod(const UGameplayPropertyMod* InMod) {
}

void UGameplayModComponent::RemoveGroupReplicated(const UGameplayPropertyModGroup* InModGroup) {
}

void UGameplayModComponent::RemoveGroup(const UGameplayPropertyModGroup* InModGroup) {
}

void UGameplayModComponent::OnRep_ModEntries() {
}

bool UGameplayModComponent::GetModBlackboardValue(const FGameplayTag& Tag, float& OutValue) const {
    return false;
}

void UGameplayModComponent::ExpungeTargetModdable(UObject* InTarget) {
}

void UGameplayModComponent::DelayedRemoveMod(const UGameplayPropertyMod* InMod) {
}

void UGameplayModComponent::ClientRemoveModManualReplication_Implementation(const UGameplayPropertyMod* InMod) {
}
bool UGameplayModComponent::ClientRemoveModManualReplication_Validate(const UGameplayPropertyMod* InMod) {
    return true;
}

void UGameplayModComponent::ClientRemoveGroupManualReplication_Implementation(const UGameplayPropertyModGroup* InModGroup) {
}
bool UGameplayModComponent::ClientRemoveGroupManualReplication_Validate(const UGameplayPropertyModGroup* InModGroup) {
    return true;
}

void UGameplayModComponent::ClientAddModManualReplication_Implementation(const UGameplayPropertyMod* InMod) {
}
bool UGameplayModComponent::ClientAddModManualReplication_Validate(const UGameplayPropertyMod* InMod) {
    return true;
}

void UGameplayModComponent::ClientAddGroupManualReplication_Implementation(const UGameplayPropertyModGroup* InModGroup) {
}
bool UGameplayModComponent::ClientAddGroupManualReplication_Validate(const UGameplayPropertyModGroup* InModGroup) {
    return true;
}

void UGameplayModComponent::AutoDetectModdables() {
}

void UGameplayModComponent::AddTargetModdable(UObject* InTarget) {
}

void UGameplayModComponent::AddModReplicated(const UGameplayPropertyMod* InMod) {
}

void UGameplayModComponent::AddMod(const UGameplayPropertyMod* InMod) {
}

void UGameplayModComponent::AddGroupReplicated(const UGameplayPropertyModGroup* InModGroup) {
}

void UGameplayModComponent::AddGroup(const UGameplayPropertyModGroup* InModGroup) {
}

void UGameplayModComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UGameplayModComponent, ModEntries);
}

UGameplayModComponent::UGameplayModComponent() {
}

