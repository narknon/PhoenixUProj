#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EUIQActionBarType.h"
#include "SpellSelectionDiamondBase.generated.h"

class USelectionRingItemBase;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API USpellSelectionDiamondBase : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedIndex;
    
public:
    USpellSelectionDiamondBase();
    UFUNCTION(BlueprintCallable)
    void SlotNewItem(const FString& NewItem, const FString& Variation, FName ItemHolder, int32 Count, EUIQActionBarType Type);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void CollectItemData(int32 GroupIndex);
    
    UFUNCTION(BlueprintCallable)
    void AddItemToWidgetArray(USelectionRingItemBase* Widget);
    
};

