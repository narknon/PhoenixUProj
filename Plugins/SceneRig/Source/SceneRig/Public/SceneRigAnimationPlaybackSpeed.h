#pragma once
#include "CoreMinimal.h"
#include "ESceneRigAnimationPlaybackSpeed.h"
#include "SceneRigAnimationPlaybackSpeed.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct FSceneRigAnimationPlaybackSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigAnimationPlaybackSpeed PlaybackType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* SpeedMultiplier;
    
    SCENERIG_API FSceneRigAnimationPlaybackSpeed();
};

