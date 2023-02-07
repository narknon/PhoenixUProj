#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUD_Clock.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UHUD_Clock : public UUserWidget {
    GENERATED_BODY()
public:
    UHUD_Clock();
    UFUNCTION(BlueprintCallable)
    void Setup();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTimeChanged(float Hour, float Minute);
    
};

