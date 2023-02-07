#pragma once
#include "CoreMinimal.h"
#include "NPC_TargetAwareStateRateSource.h"
#include "EnemyAwarenessAmendInfo.generated.h"

USTRUCT(BlueprintType)
struct FEnemyAwarenessAmendInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    NPC_TargetAwareStateRateSource AwareState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistFromPlayer;
    
    PHOENIX_API FEnemyAwarenessAmendInfo();
};

