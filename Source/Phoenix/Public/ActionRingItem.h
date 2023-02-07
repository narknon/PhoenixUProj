#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ESpellCategory.h"
#include "EUIQActionBarType.h"
#include "UIActionModes.h"
#include "ActionRingItem.generated.h"

class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class UActionRingItem : public UUserWidget {
    GENERATED_BODY()
public:
    UActionRingItem();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ToggleSelectionHighlight(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSubWidgetVisibility(EUIQActionBarType ItemType);
    
    UFUNCTION(BlueprintCallable)
    void SetSpellTool();
    
    UFUNCTION(BlueprintCallable)
    void SetItemInventoryData();
    
    UFUNCTION(BlueprintCallable)
    void SetItemData(UIActionModes ActionMode, int32 iGroupIndex, int32 iMacroIndex, int32 iItemIndex, bool ShowNone);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateMeter(float pct, bool IsASpell);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnToggleEmptyItem(bool IsEmpty);
    
    UFUNCTION(BlueprintCallable)
    void OnSpellWhitelistDeactivated(const UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void OnSpellWhitelistActivated(const UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void OnSpellCooldownChanged(FName SpellName, float CooldownPct);
    
    UFUNCTION(BlueprintCallable)
    void OnSpellCleared(const UObject* InCaller, const FName& SpellName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellCastFailed();
    
    UFUNCTION(BlueprintCallable)
    void OnSpellBlacklisted(const UObject* InCaller, const FName& SpellName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetItemInventoryData(bool IsConsumable, int32 ItemCount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOverlayTextureLoaded(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemIconTextureLoaded(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIconTextureLoaded(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIconGlowTextureLoaded(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideItemCount();
    
    UFUNCTION(BlueprintCallable)
    void OnCreateBipedPlayer(const UObject* InCaller);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MarkSpellAsBlacklisted();
    
private:
    UFUNCTION(BlueprintCallable)
    void LoadOverlayCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void LoadItemIconCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void LoadIconGlowCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void LoadIconCallback(UTexture2D* Texture, UObject* Param);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleSpellCastFailed(const UObject* InCaller, const FString& SpellStr);
    
    UFUNCTION(BlueprintCallable)
    ESpellCategory GetSpellCategory();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearSpellAsBlacklisted();
    
};

