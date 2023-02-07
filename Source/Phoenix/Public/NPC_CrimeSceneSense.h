#pragma once
#include "CoreMinimal.h"
#include "NPC_CrimeSceneSense_FOV.h"
#include "NPC_CrimeSceneSense_Hearing.h"
#include "NPC_CrimeSceneSense_LOS.h"
#include "NPC_CrimeSceneSense.generated.h"

USTRUCT(BlueprintType)
struct FNPC_CrimeSceneSense {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceiveRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoseRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EvaluateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_CrimeSceneSense_LOS LOS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_CrimeSceneSense_FOV FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_CrimeSceneSense_Hearing Hearing;
    
    PHOENIX_API FNPC_CrimeSceneSense();
};

