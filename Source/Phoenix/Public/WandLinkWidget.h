#pragma once
#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "EWandLinkInputType.h"
#include "EWandLinkMiniGameType.h"
#include "WandLinkWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWandLinkWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsingKeyboard;
    
    UWandLinkWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SuccessMeterFilled(const EWandLinkInputType InputType, const EWandLinkInputType SuccessInputType, const EWandLinkMiniGameType MiniGameType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SuccessButtonPressed(const EWandLinkInputType InputType, const EWandLinkInputType SuccessInputType, const EWandLinkMiniGameType MiniGameType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SuccessButtonFailed(const EWandLinkInputType InputType, const EWandLinkInputType SuccessInputType, const EWandLinkMiniGameType MiniGameType);
    
    UFUNCTION(BlueprintCallable)
    void Start();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMiniGameVisibility(const EWandLinkMiniGameType MiniGameType, ESlateVisibility InVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetButtonVisibility(const EWandLinkInputType InputType, ESlateVisibility InVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWandLinkPercentage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSuccessRatio() const;
    
    UFUNCTION(BlueprintCallable)
    void End();
    
};

