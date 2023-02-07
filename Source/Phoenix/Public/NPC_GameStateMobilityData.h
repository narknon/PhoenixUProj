#pragma once
#include "CoreMinimal.h"
#include "ENPC_GameState.h"
#include "ENPC_Mobility.h"
#include "NPC_GameStateMobilityData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_GameStateMobilityData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_GameState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Mobility Mobility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    PHOENIX_API FNPC_GameStateMobilityData();
};

