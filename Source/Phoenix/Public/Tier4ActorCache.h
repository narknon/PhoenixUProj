#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Tier4ActorCache.generated.h"

class UTier4ActorCache;

UCLASS(Blueprintable)
class PHOENIX_API UTier4ActorCache : public UObject {
    GENERATED_BODY()
public:
    UTier4ActorCache();
    UFUNCTION(BlueprintCallable)
    static void SetTempMaxAllowedT4(float InTempMax);
    
    UFUNCTION(BlueprintCallable)
    static UTier4ActorCache* Get();
    
    UFUNCTION(BlueprintCallable)
    static void ClearTempMaxAllowedT4();
    
};

