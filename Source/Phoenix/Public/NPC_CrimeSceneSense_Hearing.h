#pragma once
#include "CoreMinimal.h"
#include "NPC_CrimeSceneSense_Hearing.generated.h"

USTRUCT(BlueprintType)
struct FNPC_CrimeSceneSense_Hearing {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HearingRadius;
    
    PHOENIX_API FNPC_CrimeSceneSense_Hearing();
};

