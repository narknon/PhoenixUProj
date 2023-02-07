#pragma once
#include "CoreMinimal.h"
#include "NPC_TurnAssistData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_TurnAssistData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawSpringHalfLife;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawSpringMaxTurningAngle;
    
    PHOENIX_API FNPC_TurnAssistData();
};

