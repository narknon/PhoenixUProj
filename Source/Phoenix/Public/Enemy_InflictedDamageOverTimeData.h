#pragma once
#include "CoreMinimal.h"
#include "Enemy_InflictedDamageOverTime.h"
#include "Enemy_InflictedDamageOverTimeData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_InflictedDamageOverTimeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_InflictedDamageOverTime> InflictedDamageOverTimeList;
    
    PHOENIX_API FEnemy_InflictedDamageOverTimeData();
};

