#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryResult.h"
#include "QuickActionWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UQuickActionWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StartIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInventoryResult> ActionItems;
    
    UQuickActionWidget();
    UFUNCTION(BlueprintCallable)
    void SetItemArray(const TArray<FInventoryResult>& Items, int32 StartingIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitActionMenuEvent();
    
};

