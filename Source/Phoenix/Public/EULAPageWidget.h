#pragma once
#include "CoreMinimal.h"
#include "PhoenixUserWidget.h"
#include "EULAPageWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEULAPageWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UEULAPageWidget();
    UFUNCTION(BlueprintCallable)
    void ProceedToNextScreen();
    
};

