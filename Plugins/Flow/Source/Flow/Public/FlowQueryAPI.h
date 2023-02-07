#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/WorldSubsystem.h"
#include "FlowDataQueryResult.h"
#include "FlowQueryAPI.generated.h"

class UObject;

UCLASS(Blueprintable)
class FLOW_API UFlowQueryAPI : public UWorldSubsystem {
    GENERATED_BODY()
public:
    UFlowQueryAPI();
    UFUNCTION(BlueprintCallable)
    static bool QueryWaterData(const UObject* Requester, const TArray<FVector>& QueryPositions, TArray<FFlowDataQueryResult>& OutResults, bool bComputeNormals, bool bTraceRay);
    
};

