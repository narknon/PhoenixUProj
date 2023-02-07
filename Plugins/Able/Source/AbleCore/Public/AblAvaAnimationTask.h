#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.h"
#include "SkeletalMeshDriver.h"
#include "AblAbilityTask.h"
#include "AblAvaAnimationPlaybackOptions.h"
#include "AbleAvaAnimationClipRange.h"
#include "AbleAvaAnimationPlacementOptions.h"
#include "AblAvaAnimationTask.generated.h"

class UAnimationProvider;
class UBoolProvider;
class UFloatProvider;

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblAvaAnimationTask : public UAblAbilityTask, public ISkeletalMeshDriver {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProvider* AnimationProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAbleAvaAnimationPlacementOptions PlacementOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAbleAvaAnimationClipRange ClipRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblAvaAnimationPlaybackOptions PlaybackOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* ReselectOnLoopBoundaries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* BlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* LoopIndefinitely;
    
public:
    UAblAvaAnimationTask();
    
    // Fix for true pure virtual functions not being implemented
};

