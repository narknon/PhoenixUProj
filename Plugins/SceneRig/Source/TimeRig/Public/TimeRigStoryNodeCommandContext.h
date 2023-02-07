#pragma once
#include "CoreMinimal.h"
#include "TimeRigStoryNodeCommandContext.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigStoryNodeCommandContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* PreviewWorld;
    
    FTimeRigStoryNodeCommandContext();
};

