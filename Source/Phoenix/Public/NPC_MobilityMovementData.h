#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilityMovementData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_MobilityMovementData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnRate;
    
    PHOENIX_API FNPC_MobilityMovementData();
};

