#pragma once
#include "CoreMinimal.h"
#include "ENPC_Mobility.h"
#include "NPC_MobilityData.h"
#include "NPC_MobilityDataContainer.generated.h"

USTRUCT(BlueprintType)
struct FNPC_MobilityDataContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Mobility Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_MobilityData Data;
    
    PHOENIX_API FNPC_MobilityDataContainer();
};

