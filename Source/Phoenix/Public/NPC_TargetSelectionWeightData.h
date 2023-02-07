#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetSelectionWeightData.h"
#include "NPC_TargetSelectionWeightData.generated.h"

USTRUCT(BlueprintType)
struct FNPC_TargetSelectionWeightData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ENPC_TargetSelectionWeightData, float> WeightDataMap;
    
    PHOENIX_API FNPC_TargetSelectionWeightData();
};

