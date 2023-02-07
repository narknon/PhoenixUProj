#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TooltipWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTooltipWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UTooltipWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

