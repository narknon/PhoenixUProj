#pragma once
#include "CoreMinimal.h"
#include "FertilizerEffect.generated.h"

USTRUCT(BlueprintType)
struct FFertilizerEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExtraYield;
    
    PHOENIX_API FFertilizerEffect();
};

