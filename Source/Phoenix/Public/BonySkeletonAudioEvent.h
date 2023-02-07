#pragma once
#include "CoreMinimal.h"
#include "BonySkeletonTimer.h"
#include "BonySkeletonAudioEvent.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FBonySkeletonAudioEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBonySkeletonTimer Timer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* Event;
    
    PHOENIX_API FBonySkeletonAudioEvent();
};

