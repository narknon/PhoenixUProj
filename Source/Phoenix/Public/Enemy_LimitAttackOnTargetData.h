#pragma once
#include "CoreMinimal.h"
#include "Enemy_LimitAttackOnTargetData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_LimitAttackOnTargetData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToFireEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTimeout;
    
    PHOENIX_API FEnemy_LimitAttackOnTargetData();
};

