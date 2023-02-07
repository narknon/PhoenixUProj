#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EUIQActionBarType.h"
#include "CommonActionsBase.generated.h"

class UMiniSelectionDiamondBase;
class USpellSelectionDiamondBase;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UCommonActionsBase : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AvailableGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentGroupIndex;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpellSelectionDiamondBase* MainLoadout;
    
public:
    UCommonActionsBase();
    UFUNCTION(BlueprintCallable)
    void ToggleButtonCallouts(bool IsSlotting);
    
    UFUNCTION(BlueprintCallable)
    void ShowSelected(int32 GroupIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetMainLoadout(USpellSelectionDiamondBase* Loadout);
    
    UFUNCTION(BlueprintCallable)
    void SetItemData(int32 GroupIndex);
    
    UFUNCTION(BlueprintCallable)
    void PopulateMainLoadout();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnToggleButtonCallouts(bool IsSlotting);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowSpellGroupDiamond();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideSpellGroupDiamond();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivateMiniDiamond(bool Activate);
    
    UFUNCTION(BlueprintCallable)
    void HandleDPadUp();
    
    UFUNCTION(BlueprintCallable)
    void HandleDPadRight();
    
    UFUNCTION(BlueprintCallable)
    void HandleDPadLeft();
    
    UFUNCTION(BlueprintCallable)
    void HandleDPadDown();
    
    UFUNCTION(BlueprintCallable)
    void AddMiniSelectionItem(UMiniSelectionDiamondBase* Item);
    
    UFUNCTION(BlueprintCallable)
    void AddItemToGroup(const FString& ItemName, const FString& Variation, FName HolderID, int32 Amount, EUIQActionBarType ItemType);
    
    UFUNCTION(BlueprintCallable)
    void ActivateCurrentMiniDiamond(bool Activate);
    
};

