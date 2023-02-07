#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuTextButton.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMenuTextButton : public UUserWidget {
    GENERATED_BODY()
public:
    UMenuTextButton();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Exec)
    void MoveCursorToButton();
    
};

