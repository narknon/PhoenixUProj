#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ParallaxWidget.generated.h"

class UCanvasPanelSlot;

UCLASS(Blueprintable, EditInlineNew)
class UParallaxWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlideRate;
    
    UParallaxWidget();
    UFUNCTION(BlueprintCallable)
    void SyncParallaxToCursor(UCanvasPanelSlot* ParallaxingObject);
    
    UFUNCTION(BlueprintCallable)
    void SetInitialCursorPosition(UCanvasPanelSlot* ParallaxingObject);
    
    UFUNCTION(BlueprintCallable)
    void IgnoreParallax();
    
    UFUNCTION(BlueprintCallable)
    UCanvasPanelSlot* GetSlot();
    
    UFUNCTION(BlueprintCallable)
    void ApplyParallaxEffect(UCanvasPanelSlot* ParallaxingObject);
    
    UFUNCTION(BlueprintCallable)
    void ApplyParallax();
    
};

