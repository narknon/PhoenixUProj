#pragma once
#include "CoreMinimal.h"
#include "TimeRigCoordinate.generated.h"

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigCoordinate {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
public:
    FTimeRigCoordinate();
};

