#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilityAnimSpeedData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_MobilityAnimSpeedData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSpeedMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSpeedMax;
    
    PHOENIX_API FNPC_MobilityAnimSpeedData();
};

