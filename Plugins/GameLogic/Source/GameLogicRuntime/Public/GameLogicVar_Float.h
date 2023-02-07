#pragma once
#include "CoreMinimal.h"
#include "GameLogicBase.h"
#include "GameLogicVar_Float.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicVar_Float : public UGameLogicBase {
    GENERATED_BODY()
public:
    UGameLogicVar_Float();
    UFUNCTION(BlueprintCallable)
    void Subtract(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void SetCachedValue(float Value);
    
    UFUNCTION(BlueprintCallable)
    void Multiply(float Factor);
    
    UFUNCTION(BlueprintCallable)
    float GetCachedValue();
    
    UFUNCTION(BlueprintCallable)
    void Divide(float Factor);
    
    UFUNCTION(BlueprintCallable)
    void Add(float Delta);
    
};

