#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "DialogBoxScreen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDialogBoxScreen : public UScreen {
    GENERATED_BODY()
public:
    UDialogBoxScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetDialogContent(const FString& TitleText, const FString& BodyText, const FString& LegendText);
    
};

