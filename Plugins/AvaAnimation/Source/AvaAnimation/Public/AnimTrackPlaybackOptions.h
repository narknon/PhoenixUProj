#pragma once
#include "CoreMinimal.h"
#include "EAnimTrackPlaybackSpeed.h"
#include "AnimTrackPlaybackOptions.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimTrackPlaybackOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimTrackPlaybackSpeed PlayRateType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForcedDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForcedPlayRate;
    
    FAnimTrackPlaybackOptions();
};

