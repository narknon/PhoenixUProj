#pragma once
#include "CoreMinimal.h"
#include "ETimeRigEnterExitType.h"
#include "TimeRigCoordinate.h"
#include "TimeRigEnterExitEntry.generated.h"

class UTimeRigIntervalState;

USTRUCT(BlueprintType)
struct FTimeRigEnterExitEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRigEnterExitType EntryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigCoordinate TimeValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRigIntervalState* IntervalState;
    
    TIMERIG_API FTimeRigEnterExitEntry();
};

