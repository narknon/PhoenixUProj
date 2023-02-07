#pragma once
#include "CoreMinimal.h"
#include "MotionTableTransition.h"
#include "MotionTableState.generated.h"

USTRUCT(BlueprintType)
struct FMotionTableState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMotionTableTransition> Transitions;
    
    AMBULATORY_API FMotionTableState();
};

