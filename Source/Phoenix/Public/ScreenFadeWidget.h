#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "ScreenFadeCompleteEventDelegate.h"
#include "ScreenFadeWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UScreenFadeWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FadeInStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FadeOutStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoneFading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFadeSpeed;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScreenFadeCompleteEvent OnFadeInComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScreenFadeCompleteEvent OnFadeOutComplete;
    
    UScreenFadeWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UI_SetManualFade(float Opacity);
    
    UFUNCTION(BlueprintCallable)
    bool UI_IsFading();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float UI_GetCurrentFade();
    
    UFUNCTION(BlueprintCallable)
    void UI_FadeOutDone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UI_FadeOut();
    
    UFUNCTION(BlueprintCallable)
    void UI_FadeInDone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UI_FadeIn();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetFadeColor(FLinearColor TargetColor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCurtainLowered();
    
};

