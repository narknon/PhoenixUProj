#pragma once
#include "CoreMinimal.h"
#include "GameLogicBase.h"
#include "GameLogicVar_String.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicVar_String : public UGameLogicBase {
    GENERATED_BODY()
public:
    UGameLogicVar_String();
    UFUNCTION(BlueprintCallable)
    void SetCachedValue(const FString& Value);
    
    UFUNCTION(BlueprintCallable)
    FString GetCachedValue();
    
};

