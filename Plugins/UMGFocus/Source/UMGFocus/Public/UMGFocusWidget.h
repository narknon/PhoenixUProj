#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "Blueprint/UserWidget.h"
#include "EUMGInputAction.h"
#include "EUMGInputAxis.h"
#include "UMGConsolidatedAxisInputData.h"
#include "UMGFocusWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMGFOCUS_API UUMGFocusWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FocusInputPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EUMGInputAction> FocusInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EUMGInputAxis> FocusInputAxis;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FUMGConsolidatedAxisInputData ConsolidatedAxisInputData;
    
protected:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasFocus;
    
public:
    UUMGFocusWidget();
    UFUNCTION(BlueprintCallable)
    void UnregisterUMGInputAxis(EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterUMGInputAction(EUMGInputAction InputAction, EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterAllUMGInputAxis();
    
    UFUNCTION(BlueprintCallable)
    void UnregisterAllUMGInputActions(EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void RegisterUMGInputAxis(EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    void RegisterUMGInputAction(EUMGInputAction InputAction, EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void RegisterAllUMGInputAxis();
    
    UFUNCTION(BlueprintCallable)
    void RegisterAllUMGInputActions(EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void LoseFocus();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasFocus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool BlueprintOnUMGInputAction(EUMGInputAction InputAction, EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintFocusLost();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintFocusAcquired();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintConsolidatedUMGInputAxis(const FUMGConsolidatedAxisInputData& AxisInputData);
    
    UFUNCTION(BlueprintCallable)
    void AcquireFocus();
    
};

