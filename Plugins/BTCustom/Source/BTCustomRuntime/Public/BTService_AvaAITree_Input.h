#pragma once
#include "CoreMinimal.h"
#include "InputContextWithType.h"
#include "Name_GameLogicVarBool.h"
#include "BTService_AvaAITree.h"
#include "BTService_AvaAITree_Input.generated.h"

class UInputComponent;

UCLASS(Abstract, Blueprintable)
class BTCUSTOMRUNTIME_API UBTService_AvaAITree_Input : public UBTService_AvaAITree {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName_GameLogicVarBool> GameLogicBoolVars;
    
    UBTService_AvaAITree_Input();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetManagedContext(const FInputContextWithType InContext, const bool bFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayerInputSoonToBeRemoved();
    
    UFUNCTION(BlueprintCallable)
    void PlayerInputComponentCreated(const UInputComponent* InputComponent);
    
    UFUNCTION(BlueprintCallable)
    void PlayerInputComponentAboutToBeDestroyed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetManagedContext(const FInputContextWithType InContext);
    
};

