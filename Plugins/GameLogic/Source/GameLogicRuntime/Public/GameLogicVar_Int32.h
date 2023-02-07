#pragma once
#include "CoreMinimal.h"
#include "GameLogicBase.h"
#include "GameLogicVar_Int32.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicVar_Int32 : public UGameLogicBase {
    GENERATED_BODY()
public:
    UGameLogicVar_Int32();
    UFUNCTION(BlueprintCallable)
    void Subtract(int32 Delta);
    
    UFUNCTION(BlueprintCallable)
    void SetCachedValue(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void Multiply(int32 Factor);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCachedValue();
    
    UFUNCTION(BlueprintCallable)
    void Divide(int32 Denominator);
    
    UFUNCTION(BlueprintCallable)
    void Add(int32 Delta);
    
};

