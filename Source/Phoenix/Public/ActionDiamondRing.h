#pragma once
#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "HUDElementGroup.h"
#include "ActionDiamondRing.generated.h"

class AActor;
class UActionRingItem;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UActionDiamondRing : public UHUDElementGroup {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HighlightedSpellIndex;
    
public:
    UActionDiamondRing();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateMiniDiamond(int32 GroupIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowMiniDiamond();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowButtonCallouts(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowHUDElement(bool IgnoreLocks);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowButtonsChanged(bool Show);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideHUDElement(ESlateVisibility HiddenState);
    
    UFUNCTION(BlueprintCallable)
    void OnFocusChanged(AActor* Actor, float Delta);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NewDiamondSelected();
    
    UFUNCTION(BlueprintCallable)
    void CollectItemData(int32 GroupIndex);
    
    UFUNCTION(BlueprintCallable)
    void AddItemWidgetToArray(UActionRingItem* Item);
    
};

