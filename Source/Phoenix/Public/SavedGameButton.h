#pragma once
#include "CoreMinimal.h"
#include "PhoenixUserWidget.h"
#include "SavedGameButton.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USavedGameButton : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    USavedGameButton();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Exec)
    void MoveCursorToButton();
    
};

