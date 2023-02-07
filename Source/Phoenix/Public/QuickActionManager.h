#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EUIQActionBarType.h"
#include "QuickActionManager.generated.h"

class UQuickActionManager;

UCLASS(Blueprintable)
class UQuickActionManager : public UObject {
    GENERATED_BODY()
public:
    UQuickActionManager();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ValidateDefaultGroupSelections(int32 GroupIndex);
    
    UFUNCTION(BlueprintCallable)
    void UseQuickWheelItem();
    
    UFUNCTION(BlueprintCallable)
    static void UpdateSelectedActionItem(const FString& ItemName, const FString& ItemVariation, EUIQActionBarType ItemType, const FString& ItemHolder, int32 RequestedGroupIndex, int32 Amount, int32 RequestedMacroIndex, int32 Index);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SlotToolFromCode(const FString& ItemId, int32 Slot);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SlotSpellFromCode(const FString& SpellID, int32 Slot, int32 Group);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SlotInventoryItemFromCode(const FString& ItemId, int32 Amount, int32 Slot);
    
    UFUNCTION(BlueprintCallable)
    void SetQuickWheelItem(FName ItemName);
    
    UFUNCTION(BlueprintCallable)
    static void SetQuickActionTrigger();
    
    UFUNCTION(BlueprintCallable)
    static void SetInventoryActionItemIntoCurrentSlot(const FString& ItemName, EUIQActionBarType ItemType, int32 Count, const FName ItemVariation);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentGroupIndex(int32 NewIndex);
    
    UFUNCTION(BlueprintCallable)
    static void ResetMacro();
    
    UFUNCTION(BlueprintCallable)
    void ReplaceItemOnDiamond(FName HolderID, FName NewItem);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveActionGroupOverride(const FString& OverrideName);
    
    UFUNCTION(BlueprintCallable)
    void RemoveActionFromDiamond(FName ItemName);
    
    UFUNCTION(BlueprintCallable)
    static void OverrideActionGroups(const FString& OverrideName);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnAboutToSaveGame();
    
    UFUNCTION(BlueprintCallable)
    static void NewMacroSelectedForMode(int32 MacroIndex, int32 RequestedGroupIndex);
    
    UFUNCTION(BlueprintCallable)
    static void NewMacroSelected(int32 MacroIndex, int32 RequestedGroupIndex);
    
    UFUNCTION(BlueprintCallable)
    static bool IsMacroIndexValid(int32 MacroIndex);
    
    UFUNCTION(BlueprintCallable)
    void InitializeLoadouts();
    
    UFUNCTION(BlueprintCallable)
    static void IncMacroIndex(int32 GroupIndex, bool AllowNone, int32 CapIndexAt);
    
    UFUNCTION(BlueprintCallable)
    static void IncGroupIndex();
    
    UFUNCTION(BlueprintCallable)
    void HandleMapLocationChanged(const UObject* Caller, const FString& CurrentMapLocationName);
    
    UFUNCTION(BlueprintCallable)
    static void GotoPrevGroup();
    
    UFUNCTION(BlueprintCallable)
    static void GotoNextGroup();
    
    UFUNCTION(BlueprintCallable)
    static void GetWorldStorageOverride(const FString& ItemName, FString& Storage);
    
    UFUNCTION(BlueprintCallable)
    static bool GetTwitchItem(int32 GroupIndex, int32 ItemIndex, FName& ItemName);
    
    UFUNCTION(BlueprintCallable)
    FName GetQuickWheelItem();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPrevGroupIndex();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetNumActionsInGroup(int32 GroupIndex);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetNextGroupIndex();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMacroItemCount(int32 GroupIndex, int32 MacroIndex);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMacroIndexByName(const FString& ItemName);
    
    UFUNCTION(BlueprintCallable)
    static EUIQActionBarType GetItemType(int32 GroupIndex, int32 MacroIndex, int32 ItemIndex);
    
    UFUNCTION(BlueprintCallable)
    static void GetItemNameFromMode(int32 GroupIndex, int32 MacroIndex, int32 ActionIndex, FName& ItemName);
    
    UFUNCTION(BlueprintCallable)
    static void GetItemName(int32 GroupIndex, int32 MacroIndex, int32 ActionIndex, FName& ItemName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetItemCount(int32 GroupIndex, int32 MacroIndex, int32 ItemIndex);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetActiveMacroIndex();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetActiveGroupIndex();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetActionGroupCount();
    
    UFUNCTION(BlueprintCallable)
    static UQuickActionManager* Get();
    
    UFUNCTION(BlueprintCallable)
    static bool DoesSelectedTransfigurationSpellAffectObject(const FName InDbID);
    
    UFUNCTION(BlueprintCallable)
    static void DecMacroIndex(int32 GroupIndex, bool AllowNone, int32 CapIndexAt);
    
    UFUNCTION(BlueprintCallable)
    static void DecGroupIndex();
    
    UFUNCTION(BlueprintCallable)
    void ContextChanged(bool bNewResult);
    
    UFUNCTION(BlueprintCallable)
    void ContextAdded(FName InContextName);
    
    UFUNCTION(BlueprintCallable)
    void ClearCurWorld();
    
    UFUNCTION(BlueprintCallable)
    static void ClearContextCallbacks();
    
    UFUNCTION(BlueprintCallable)
    void CheckForWorldOverrides();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddAncientMagicPoints(int32 NumPoints);
    
};

