#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackRangeData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_AttackRangeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeProbability;
    
    PHOENIX_API FEnemy_AttackRangeData();
};

