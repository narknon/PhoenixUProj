#pragma once
#include "CoreMinimal.h"
#include "TimeRigScratchAnimation.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigScratchAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimSequence* Animation;
    
    FTimeRigScratchAnimation();
};

