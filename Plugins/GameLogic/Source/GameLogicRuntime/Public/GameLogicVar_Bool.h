#pragma once
#include "CoreMinimal.h"
#include "GameLogicBoolBase.h"
#include "GameLogicVar_Bool.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicVar_Bool : public UGameLogicBoolBase {
    GENERATED_BODY()
public:
    UGameLogicVar_Bool();
    UFUNCTION(BlueprintCallable)
    void SetCachedValue(bool bValue);
    
};

