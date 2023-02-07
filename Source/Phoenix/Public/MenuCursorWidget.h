#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuCursorWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMenuCursorWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsScaledDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DefaultExpandState;
    
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
    
    UMenuCursorWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTooltipExpandState(bool IsExpanded, bool ShouldAnimate);
    
    UFUNCTION(BlueprintCallable)
    void ScaleCursor(bool IsHover);
    
    UFUNCTION(BlueprintCallable)
    void ResetTooltipState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnScaleCursor();
    
    UFUNCTION(BlueprintCallable)
    void Cursor_FadeOutDone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Cursor_FadeOut();
    
    UFUNCTION(BlueprintCallable)
    void Cursor_FadeInDone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Cursor_FadeIn();
    
};

