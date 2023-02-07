#pragma once
#include "CoreMinimal.h"
#include "GameLogicBase.h"
#include "GameLogicBoolBase.generated.h"

UCLASS(Abstract, Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicBoolBase : public UGameLogicBase {
    GENERATED_BODY()
public:
    UGameLogicBoolBase();
    UFUNCTION(BlueprintCallable)
    bool GetCachedValue();
    
};

