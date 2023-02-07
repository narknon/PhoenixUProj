#pragma once
#include "CoreMinimal.h"
#include "Enemy_MobilityData.h"
#include "Enemy_DistanceMobilityData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_DistanceMobilityData : public FEnemy_MobilityData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMax;
    
    PHOENIX_API FEnemy_DistanceMobilityData();
};

