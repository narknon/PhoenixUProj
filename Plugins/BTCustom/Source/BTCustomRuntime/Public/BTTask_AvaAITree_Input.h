#pragma once
#include "CoreMinimal.h"
#include "EManagedFacialAnimationPriority.h"
#include "FacialAnimation.h"
#include "InputContextWithType.h"
#include "Name_GameLogicVarBool.h"
#include "BTCustomAction.h"
#include "BTTask_AvaAITree.h"
#include "BTTask_AvaAITree_Input.generated.h"

class UInputComponent;

UCLASS(Abstract, Blueprintable)
class UBTTask_AvaAITree_Input : public UBTTask_AvaAITree {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName_GameLogicVarBool> GameLogicBoolVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBTCustomAction> CustomActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialAnimation FacialAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedFacialAnimationPriority FacialAnimationPriority;
    
    UBTTask_AvaAITree_Input();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetManagedContext(const FInputContextWithType InContext, const bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void PlayerInputComponentCreated(const UInputComponent* InputComponent);
    
    UFUNCTION(BlueprintCallable)
    void PlayerInputComponentAboutToBeDestroyed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetManagedContext(const FInputContextWithType InContext);
    
};

