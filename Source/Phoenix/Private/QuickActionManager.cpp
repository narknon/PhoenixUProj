#include "QuickActionManager.h"

class UObject;
class UQuickActionManager;

bool UQuickActionManager::ValidateDefaultGroupSelections(int32 GroupIndex) {
    return false;
}

void UQuickActionManager::UseQuickWheelItem() {
}

void UQuickActionManager::UpdateSelectedActionItem(const FString& ItemName, const FString& ItemVariation, EUIQActionBarType ItemType, const FString& ItemHolder, int32 RequestedGroupIndex, int32 Amount, int32 RequestedMacroIndex, int32 Index) {
}

void UQuickActionManager::SlotToolFromCode(const FString& ItemId, int32 Slot) {
}

void UQuickActionManager::SlotSpellFromCode(const FString& SpellID, int32 Slot, int32 Group) {
}

void UQuickActionManager::SlotInventoryItemFromCode(const FString& ItemId, int32 Amount, int32 Slot) {
}

void UQuickActionManager::SetQuickWheelItem(FName ItemName) {
}

void UQuickActionManager::SetQuickActionTrigger() {
}

void UQuickActionManager::SetInventoryActionItemIntoCurrentSlot(const FString& ItemName, EUIQActionBarType ItemType, int32 Count, const FName ItemVariation) {
}

void UQuickActionManager::SetCurrentGroupIndex(int32 NewIndex) {
}

void UQuickActionManager::ResetMacro() {
}

void UQuickActionManager::ReplaceItemOnDiamond(FName HolderID, FName NewItem) {
}

void UQuickActionManager::RemoveActionGroupOverride(const FString& OverrideName) {
}

void UQuickActionManager::RemoveActionFromDiamond(FName ItemName) {
}

void UQuickActionManager::OverrideActionGroups(const FString& OverrideName) {
}

void UQuickActionManager::OnSaveGameLoaded() {
}

void UQuickActionManager::OnAboutToSaveGame() {
}

void UQuickActionManager::NewMacroSelectedForMode(int32 MacroIndex, int32 RequestedGroupIndex) {
}

void UQuickActionManager::NewMacroSelected(int32 MacroIndex, int32 RequestedGroupIndex) {
}

bool UQuickActionManager::IsMacroIndexValid(int32 MacroIndex) {
    return false;
}

void UQuickActionManager::InitializeLoadouts() {
}

void UQuickActionManager::IncMacroIndex(int32 GroupIndex, bool AllowNone, int32 CapIndexAt) {
}

void UQuickActionManager::IncGroupIndex() {
}

void UQuickActionManager::HandleMapLocationChanged(const UObject* Caller, const FString& CurrentMapLocationName) {
}

void UQuickActionManager::GotoPrevGroup() {
}

void UQuickActionManager::GotoNextGroup() {
}

void UQuickActionManager::GetWorldStorageOverride(const FString& ItemName, FString& Storage) {
}

bool UQuickActionManager::GetTwitchItem(int32 GroupIndex, int32 ItemIndex, FName& ItemName) {
    return false;
}

FName UQuickActionManager::GetQuickWheelItem() {
    return NAME_None;
}

int32 UQuickActionManager::GetPrevGroupIndex() {
    return 0;
}

int32 UQuickActionManager::GetNumActionsInGroup(int32 GroupIndex) {
    return 0;
}

int32 UQuickActionManager::GetNextGroupIndex() {
    return 0;
}

int32 UQuickActionManager::GetMacroItemCount(int32 GroupIndex, int32 MacroIndex) {
    return 0;
}

int32 UQuickActionManager::GetMacroIndexByName(const FString& ItemName) {
    return 0;
}

EUIQActionBarType UQuickActionManager::GetItemType(int32 GroupIndex, int32 MacroIndex, int32 ItemIndex) {
    return EUIQActionBarType::QuickAction_Spells;
}

void UQuickActionManager::GetItemNameFromMode(int32 GroupIndex, int32 MacroIndex, int32 ActionIndex, FName& ItemName) {
}

void UQuickActionManager::GetItemName(int32 GroupIndex, int32 MacroIndex, int32 ActionIndex, FName& ItemName) {
}

int32 UQuickActionManager::GetItemCount(int32 GroupIndex, int32 MacroIndex, int32 ItemIndex) {
    return 0;
}

int32 UQuickActionManager::GetActiveMacroIndex() {
    return 0;
}

int32 UQuickActionManager::GetActiveGroupIndex() {
    return 0;
}

int32 UQuickActionManager::GetActionGroupCount() {
    return 0;
}

UQuickActionManager* UQuickActionManager::Get() {
    return NULL;
}

bool UQuickActionManager::DoesSelectedTransfigurationSpellAffectObject(const FName InDbID) {
    return false;
}

void UQuickActionManager::DecMacroIndex(int32 GroupIndex, bool AllowNone, int32 CapIndexAt) {
}

void UQuickActionManager::DecGroupIndex() {
}

void UQuickActionManager::ContextChanged(bool bNewResult) {
}

void UQuickActionManager::ContextAdded(FName InContextName) {
}

void UQuickActionManager::ClearCurWorld() {
}

void UQuickActionManager::ClearContextCallbacks() {
}

void UQuickActionManager::CheckForWorldOverrides() {
}

void UQuickActionManager::AddAncientMagicPoints(int32 NumPoints) {
}

UQuickActionManager::UQuickActionManager() {
}

