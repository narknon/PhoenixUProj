#pragma once
#include "CoreMinimal.h"
#include "TimeRigEventToHandle.generated.h"

class UTimeRigElementState;

USTRUCT(BlueprintType)
struct FTimeRigEventToHandle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRigElementState* ElementState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    TIMERIG_API FTimeRigEventToHandle();
};

