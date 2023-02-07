#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineBaseTypes.h"
#include "EUMGInputAction.h"
#include "EUMGInputAxis.h"
#include "UMGInputActionInfo.h"
#include "UMGInputListener.h"
#include "UMGInputListenerStack.h"
#include "UMGInputManager.generated.h"

UCLASS(Blueprintable)
class UMGFOCUS_API AUMGInputManager : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EUMGInputAction ReferenceUMGInputAction;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EUMGInputAxis ReferenceUMGInputAxis;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FUMGInputActionInfo, FUMGInputListenerStack> UMGInputActionListeners;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<EUMGInputAxis, FUMGInputListenerStack> UMGInputAxisListeners;
    
public:
    AUMGInputManager();
    UFUNCTION(BlueprintCallable)
    void UnregisterUMGInputListener(FUMGInputListener& InputListener);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterUMGInputAxis(FUMGInputListener& InputListener, EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterUMGInputAction(FUMGInputListener& InputListener, EUMGInputAction InputAction, EInputEvent InputEvent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void UnregisterInputAxis(EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterInputAction(EUMGInputAction InputAction, EInputEvent InputEvent);
    
public:
    UFUNCTION(BlueprintCallable)
    void RegisterUMGInputAxis(FUMGInputListener& InputListener, EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    void RegisterUMGInputAction(FUMGInputListener& InputListener, EUMGInputAction InputAction, EInputEvent InputEvent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RegisterInputAxis(EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    void RegisterInputAction(EUMGInputAction InputAction, EInputEvent InputEvent);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnInputAxis(EUMGInputAxis InputAxis, const float AxisValue);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction(EUMGInputAction InputAction, EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable)
    FString GetInputAxisEnumValueAsString(EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    FString GetInputActionEnumValueAsString(EUMGInputAction InputAction);
    
protected:
    UFUNCTION(BlueprintCallable)
    void CreateInputAxisBinding(EUMGInputAxis InputAxis);
    
    UFUNCTION(BlueprintCallable)
    void CreateInputActionBinding(EUMGInputAction InputAction, EInputEvent InputEvent);
    
};

