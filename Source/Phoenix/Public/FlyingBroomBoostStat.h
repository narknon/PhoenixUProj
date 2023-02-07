#pragma once
#include "CoreMinimal.h"
#include "FlyingBroomBoostStat.generated.h"

USTRUCT(BlueprintType)
struct FFlyingBroomBoostStat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightFromGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RechargeRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecayRate;
    
    PHOENIX_API FFlyingBroomBoostStat();
};

