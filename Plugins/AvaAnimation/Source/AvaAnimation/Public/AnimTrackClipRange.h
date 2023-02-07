#pragma once
#include "CoreMinimal.h"
#include "AnimTrackRangedFloat.h"
#include "EAnimTrackPlaybackRange.h"
#include "AnimTrackClipRange.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimTrackClipRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimTrackPlaybackRange RangeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimTrackRangedFloat TimingOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimTrackRangedFloat StartOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimTrackRangedFloat EndOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimTrackRangedFloat Duration;
    
    FAnimTrackClipRange();
};

