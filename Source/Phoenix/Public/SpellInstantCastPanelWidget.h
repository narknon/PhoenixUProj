#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Blueprint/UserWidget.h"
#include "SpellInstantCastPanelWidget.generated.h"

class ABiped_Character;
class AWandTool;
class UImage;
class USpellBarSlotWidget;
class UTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class USpellInstantCastPanelWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AWandTool* Wand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ABiped_Character* BipedCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USpellBarSlotWidget*> SpellBarDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NextLoadout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpellGroupIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlateBrush> SpellGroupIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpellBarSlotWidget* Spell_0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpellBarSlotWidget* Spell_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* SpellNameText_0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* SpellNameText_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* SpellGroupIcon;
    
    USpellInstantCastPanelWidget();
    UFUNCTION(BlueprintCallable)
    void UpdateSpellGroup(bool OutAnimDone);
    
    UFUNCTION(BlueprintCallable)
    void UpdateSlotState(bool IsActive);
    
    UFUNCTION(BlueprintCallable)
    void UpdateAvailableSpellList(bool Next);
    
    UFUNCTION(BlueprintCallable)
    void ShowSpellPanel(bool Show);
    
    UFUNCTION(BlueprintCallable)
    void SetSpellName(FText NewName, int32 SpellIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateSpellGroup();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateAvailableSpellList();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeactivateWand();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivateWand();
    
    UFUNCTION(BlueprintCallable)
    void InitSpells();
    
    UFUNCTION(BlueprintCallable)
    void GetSpellData();
    
};

