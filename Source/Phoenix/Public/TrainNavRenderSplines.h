#pragma once
#include "CoreMinimal.h"
#include "ETrainSplineDirection.h"
#include "TrainNavRenderSplines.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FTrainNavRenderSplines {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<AActor> RenderSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrainSplineDirection Directon;
    
    PHOENIX_API FTrainNavRenderSplines();
};

