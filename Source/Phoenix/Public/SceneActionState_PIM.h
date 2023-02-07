#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableInterface.h"
#include "InputCoreTypes.h"
#include "SceneRigObjectActionState.h"
#include "ESpellButton.h"
#include "SceneActionState_PIM.generated.h"

class UGlobalLightingCustomBlendableFocusValue;
class USceneRigInputScreen;
class UUserWidget;

UCLASS(Blueprintable)
class USceneActionState_PIM : public USceneRigObjectActionState, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGlobalLightingCustomBlendableFocusValue* CustomFocusBlendable;
    
public:
    USceneActionState_PIM();
protected:
    UFUNCTION(BlueprintCallable)
    void WidgetLoaded(TSoftClassPtr<USceneRigInputScreen> WidgetClassPtr);
    
    UFUNCTION(BlueprintCallable)
    void TelescopeWidgetLoaded(TSoftClassPtr<UUserWidget> WidgetClassPtr);
    
    UFUNCTION(BlueprintCallable)
    void HandleWildcardAxisChanged(float AxisVal);
    
    UFUNCTION(BlueprintCallable)
    void HandleWildcardActionReleased();
    
    UFUNCTION(BlueprintCallable)
    void HandleWildcardActionPressed();
    
    UFUNCTION(BlueprintCallable)
    void HandleSpellButtonPressed(ESpellButton SpellButton);
    
    UFUNCTION(BlueprintCallable)
    void HandleModifierReleased();
    
    UFUNCTION(BlueprintCallable)
    void HandleModifierPressed();
    
    UFUNCTION(BlueprintCallable)
    void HandleModifierAxisChanged(float AxisVal);
    
    UFUNCTION(BlueprintCallable)
    void HandleAnalogStick(FKey Key, float AnalogValue);
    
    UFUNCTION(BlueprintCallable)
    void HandleAcceptActionReleased();
    
    UFUNCTION(BlueprintCallable)
    void HandleAcceptActionPressed();
    
    UFUNCTION(BlueprintCallable)
    void FinishNow(const bool bSuccess);
    
    
    // Fix for true pure virtual functions not being implemented
};

