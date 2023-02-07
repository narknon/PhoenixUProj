#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilityAnimBlendSpaceData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_MobilityAnimBlendSpaceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float XInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YInterpSpeed;
    
    PHOENIX_API FNPC_MobilityAnimBlendSpaceData();
};

