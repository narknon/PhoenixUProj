#pragma once
#include "CoreMinimal.h"
#include "Enemy_InflictedDamageOverTime.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_InflictedDamageOverTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FromTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FromNPCDamageMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FromPlayerDamageMult;
    
    PHOENIX_API FEnemy_InflictedDamageOverTime();
};

