#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpingModifierConfig_Warp.h"
#include "AvaRootMotionWarper.h"
#include "EMotionWarpRotationType.h"
#include "AvaMotionWarpingModifierConfig_SkewWarp.generated.h"

class UAnimSequenceBase;
class UAvaMotionWarpWindowFinder;

UCLASS(Blueprintable, EditInlineNew)
class AMBULATORY_API UAvaMotionWarpingModifierConfig_SkewWarp : public UAvaMotionWarpingModifierConfig_Warp {
    GENERATED_BODY()
public:
    UAvaMotionWarpingModifierConfig_SkewWarp();
    UFUNCTION(BlueprintCallable)
    static void AddMotionWarpingModifierSkewWarp(FAvaRootMotionWarper& InMotionWarper, UAvaMotionWarpWindowFinder* InWindowFinder, const UAnimSequenceBase* InAnimation, float InStartTime, float InEndTime, FName InSyncPointName, bool bInWarpTranslation, bool bInIgnoreZAxis, bool bInWarpRotation, EMotionWarpRotationType InRotationType, float InWarpRotationTimeMultiplier);
    
};

