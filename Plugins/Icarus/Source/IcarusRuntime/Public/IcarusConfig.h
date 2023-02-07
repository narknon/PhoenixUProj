#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "IcarusConfig.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=IcarusConfig)
class ICARUSRUNTIME_API UIcarusConfig : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BehaviorCirclingMinimumValidPointsRatio;
    
    UIcarusConfig();
};

