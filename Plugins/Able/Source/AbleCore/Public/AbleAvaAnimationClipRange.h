#pragma once
#include "CoreMinimal.h"
#include "AbleAvaAnimationClipRange.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct ABLECORE_API FAbleAvaAnimationClipRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* StartOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* EndOffset;
    
    FAbleAvaAnimationClipRange();
};

