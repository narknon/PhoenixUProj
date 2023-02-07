#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilitySpeedData.generated.h"

class UNPC_MobilitySpeedChoice;

USTRUCT(BlueprintType)
struct FNPC_MobilitySpeedData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNPC_MobilitySpeedChoice* SpeedChoice;
    
    PHOENIX_API FNPC_MobilitySpeedData();
};

