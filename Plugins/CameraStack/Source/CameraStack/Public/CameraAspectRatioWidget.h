#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CameraAspectRatioWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCameraAspectRatioWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UCameraAspectRatioWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UI_UpdatePillarbox(float InBarScale);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UI_UpdateLetterbox(float InBarScale);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UI_HideBars();
    
};

