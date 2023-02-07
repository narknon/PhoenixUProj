#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OptionsWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UOptionsWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UOptionsWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReturnToFrontEndMenu();
    
};

