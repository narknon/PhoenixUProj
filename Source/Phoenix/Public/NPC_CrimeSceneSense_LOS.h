#pragma once
#include "CoreMinimal.h"
#include "NPC_CrimeSceneSense_LOS.generated.h"

USTRUCT(BlueprintType)
struct FNPC_CrimeSceneSense_LOS {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLOS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LOSInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LOSMinDist;
    
    PHOENIX_API FNPC_CrimeSceneSense_LOS();
};

