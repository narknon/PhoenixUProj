#pragma once
#include "CoreMinimal.h"
#include "ESceneRigAnimationPlaybackRange.h"
#include "SceneRigAnimationClipRange.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct FSceneRigAnimationClipRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigAnimationPlaybackRange RangeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* TimingOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* StartOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* EndOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Duration;
    
    SCENERIG_API FSceneRigAnimationClipRange();
};

