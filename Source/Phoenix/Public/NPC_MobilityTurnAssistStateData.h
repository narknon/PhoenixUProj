#pragma once
#include "CoreMinimal.h"
#include "ENPC_MobilityTurnAssistStartMode.h"
#include "ENPC_TurnAssistState.h"
#include "NPC_MobilityTurnAssistStateData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_MobilityTurnAssistStateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssistState MoveTurnTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssistState MoveStartTurnTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssistState MoveStopTurnTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_MobilityTurnAssistStartMode MoveStartMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveStartDelayedStartTime;
    
    PHOENIX_API FNPC_MobilityTurnAssistStateData();
};

