#pragma once
#include "CoreMinimal.h"
#include "LandscapePointData.h"
#include "LandscapeRoadData.generated.h"

USTRUCT(BlueprintType)
struct FLandscapeRoadData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLandscapePointData> RoadPoints;
    
    UTILITIESRUNTIME_API FLandscapeRoadData();
};

