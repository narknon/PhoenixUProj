#pragma once
#include "CoreMinimal.h"
#include "EUMGInputAction.h"
#include "EUIQActionBarType.h"
#include "Screen.h"
#include "ActionSelectionScreenBase.generated.h"

class UCommonActionsBase;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UActionSelectionScreenBase : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCommonActionsBase* CommonActionsCode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentHighlightedItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentHighlightedItemVariation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurrentHighlightedItemHolder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUIQActionBarType CurrentHighlightedItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsSpellVideoShowing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TutorialName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotTutorialStepName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CurrentHighlightedItemIsUnlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CurrentHighlightedItemIsBlacklisted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InSlottingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TutorializedSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequestedSpellSlotted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NeedsAutosave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LeviosoTutorialActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AccioTutorialActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool VanishmentTutorialActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConjurationTutorialActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CreatureBrushTutorialActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CreatureFeedTutorialActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlterationTutorialActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EquippingIncendioTutorialActive;
    
public:
    UActionSelectionScreenBase();
    UFUNCTION(BlueprintCallable)
    void UpdateMacroCode(const FString& ItemName, const FString& Variation, FName HolderID, EUIQActionBarType ItemType);
    
    UFUNCTION(BlueprintCallable)
    void ToggleListenForSpellSlottingEvents(bool ShouldListen);
    
    UFUNCTION(BlueprintCallable)
    void ToggleListenForSpellGroupEvents(bool ShouldListen);
    
    UFUNCTION(BlueprintCallable)
    void SetSlottedSpells();
    
    UFUNCTION(BlueprintCallable)
    void SetItemDataCode(int32 GroupId);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellSelectedBP(const UObject* SpellObject);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellHoveredBP(const UObject* SpellObject);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowButtonsChanged(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetSlottedSpells(const TArray<FString>& SlottedSpells);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRequestedSpellSlotted(const FString& SpellName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideSpellPreviewer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideCursor();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHandleRightTriggerRelease();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHandleRightTriggerPress();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHandleDirectionalButtonInput();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitRequested();
    
    UFUNCTION(BlueprintCallable)
    void OnChangeDiamondTop();
    
    UFUNCTION(BlueprintCallable)
    void OnChangeDiamondRight();
    
    UFUNCTION(BlueprintCallable)
    void OnChangeDiamondLeft();
    
    UFUNCTION(BlueprintCallable)
    void OnChangeDiamondBottom();
    
    UFUNCTION(BlueprintCallable)
    void OnCastTopSpell();
    
    UFUNCTION(BlueprintCallable)
    void OnCastRightSpell();
    
    UFUNCTION(BlueprintCallable)
    void OnCastLeftSpell();
    
    UFUNCTION(BlueprintCallable)
    void OnCastBottomSpell();
    
    UFUNCTION(BlueprintCallable)
    void HideCursorIfInTutorial();
    
    UFUNCTION(BlueprintCallable)
    bool HandleViewSpellButtonPress();
    
    UFUNCTION(BlueprintCallable)
    bool HandleRightTriggerRelease();
    
    UFUNCTION(BlueprintCallable)
    bool HandleRightTriggerPress();
    
    UFUNCTION(BlueprintCallable)
    bool HandleKeyUp(EUMGInputAction InputAction);
    
    UFUNCTION(BlueprintCallable)
    bool HandleKeyDown(EUMGInputAction InputAction);
    
    UFUNCTION(BlueprintCallable)
    bool HandleCloseScreenButtonPress();
    
    UFUNCTION(BlueprintCallable)
    bool HandleBackButtonPress();
    
    UFUNCTION(BlueprintCallable)
    void ExitActionSelection();
    
    UFUNCTION(BlueprintCallable)
    bool CanSlotSpell();
    
    UFUNCTION(BlueprintCallable)
    bool CanExitScreen();
    
    UFUNCTION(BlueprintCallable)
    void AttachCommonAction(UCommonActionsBase* ActionsWidget);
    
};

