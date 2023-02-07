#pragma once
#include "CoreMinimal.h"
#include "EAnimTrackPlaybackSpeed.h"
#include "AblAvaAnimationPlaybackOptions.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct ABLECORE_API FAblAvaAnimationPlaybackOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimTrackPlaybackSpeed PlayRateType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* ForcedDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* ForcedPlayRate;
    
    FAblAvaAnimationPlaybackOptions();
};

