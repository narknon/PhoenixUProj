#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MotionTableTransition.generated.h"

USTRUCT(BlueprintType)
struct FMotionTableTransition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TransitionDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TransitionTravelDistance;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFloatInterval> TransitionMarkerTimes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetStateCycleTime;
    
    AMBULATORY_API FMotionTableTransition();
};

