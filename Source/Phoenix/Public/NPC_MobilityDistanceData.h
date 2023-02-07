#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilityDistanceData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_MobilityDistanceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMax;
    
    PHOENIX_API FNPC_MobilityDistanceData();
};

