#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LegendBox.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ULegendBox : public UUserWidget {
    GENERATED_BODY()
public:
    ULegendBox();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Exec)
    void MoveCursorToButton();
    
};

