#pragma once
#include "CoreMinimal.h"
#include "ENPC_TurnAssist.h"
#include "NPC_TurnAssistData.h"
#include "NPC_TurnAssistDataContainer.generated.h"

USTRUCT(BlueprintType)
struct FNPC_TurnAssistDataContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssist Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_TurnAssistData Data;
    
    PHOENIX_API FNPC_TurnAssistDataContainer();
};

