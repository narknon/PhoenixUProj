#include "FlowQueryAPI.h"

class UObject;

bool UFlowQueryAPI::QueryWaterData(const UObject* Requester, const TArray<FVector>& QueryPositions, TArray<FFlowDataQueryResult>& OutResults, bool bComputeNormals, bool bTraceRay) {
    return false;
}

UFlowQueryAPI::UFlowQueryAPI() {
}

