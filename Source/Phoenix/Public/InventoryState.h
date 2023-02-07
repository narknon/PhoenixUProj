#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineBaseTypes.h"
#include "EUMGInputAction.h"
#include "EInventorySortType.h"
#include "EInventoryTabCategory.h"
#include "InventoryHolder.h"
#include "InventoryResult.h"
#include "LegendItemData.h"
#include "InventoryState.generated.h"

class UUserWidget;

UCLASS(Blueprintable)
class UInventoryState : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* InventoryOwner;
    
public:
    UInventoryState();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEndState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitializeState(UUserWidget* OwningWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HandleUMGInputAction(EUMGInputAction InputAction, EInputEvent InputEvent, UUserWidget* InventoryButton);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HandleClicked(UUserWidget* InventoryButton);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetTooltipLegendData(FInventoryResult InventoryItem, TArray<FLegendItemData>& LegendData);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UUserWidget* GetTooltipContent(UUserWidget* hoveredButton);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<UUserWidget*> GetNonExpandableTooltipContent(UUserWidget* hoveredButton);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FString GetMenuTitle(EInventoryTabCategory TabCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TArray<FInventoryHolder> GetInventoryItemData(const EInventorySortType SortType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    EInventoryTabCategory GetDefaultInventoryTab();
    
};

