#pragma once
#include "CoreMinimal.h"
#include "AblAnimationChannel.h"
#include "AblAnimation.generated.h"

USTRUCT(BlueprintType)
struct ABLECORE_API FAblAnimation {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAblAnimationChannel> SortedAnimationChannels;
    
public:
    FAblAnimation();
};

