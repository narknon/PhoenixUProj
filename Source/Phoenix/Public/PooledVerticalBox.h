#pragma once
#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Components/SlateWrapperTypes.h"
#include "Components/VerticalBox.h"
#include "PooledVerticalBox.generated.h"

class UWidget;

UCLASS(Blueprintable)
class PHOENIX_API UPooledVerticalBox : public UVerticalBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESlateVisibility DesiredChildVisibility;
    
    UPooledVerticalBox();
    UFUNCTION(BlueprintCallable)
    void SetChildWidgetPool(TArray<UWidget*> ChildWidgets, FMargin Padding);
    
    UFUNCTION(BlueprintCallable)
    void SetChildActive(UWidget* ChildWidget, bool IsActive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsChildAvailable(UWidget* ChildWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsChildActive(UWidget* ChildWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWidget* GetNextAvailableChild();
    
};

