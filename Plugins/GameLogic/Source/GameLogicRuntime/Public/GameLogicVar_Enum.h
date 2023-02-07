#pragma once
#include "CoreMinimal.h"
#include "GameLogicBase.h"
#include "GameLogicVar_Enum.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicVar_Enum : public UGameLogicBase {
    GENERATED_BODY()
public:
    UGameLogicVar_Enum();
    UFUNCTION(BlueprintCallable)
    void SetCachedValue(uint8 Value);
    
    UFUNCTION(BlueprintCallable)
    uint8 GetCachedValue();
    
};

