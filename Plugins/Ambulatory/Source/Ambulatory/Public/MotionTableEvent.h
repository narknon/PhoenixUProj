#pragma once
#include "CoreMinimal.h"
#include "MotionTableEventState.h"
#include "MotionTableEvent.generated.h"

USTRUCT(BlueprintType)
struct FMotionTableEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMotionTableEventState> EventStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> StateToEventStateMap;
    
    AMBULATORY_API FMotionTableEvent();
};

