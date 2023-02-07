#pragma once
#include "CoreMinimal.h"
#include "NPC_CrimeSceneSense_FOV.generated.h"

USTRUCT(BlueprintType)
struct FNPC_CrimeSceneSense_FOV {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOVDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOVHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOVFalloffScale;
    
    PHOENIX_API FNPC_CrimeSceneSense_FOV();
};

