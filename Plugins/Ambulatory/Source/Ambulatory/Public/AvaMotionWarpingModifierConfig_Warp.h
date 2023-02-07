#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpingModifierConfig.h"
#include "AvaRootMotionWarper.h"
#include "EMotionWarpRotationType.h"
#include "AvaMotionWarpingModifierConfig_Warp.generated.h"

class UAnimSequenceBase;
class UAvaMotionWarpWindowFinder;

UCLASS(Blueprintable, EditInlineNew)
class AMBULATORY_API UAvaMotionWarpingModifierConfig_Warp : public UAvaMotionWarpingModifierConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SyncPointName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWarpTranslation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisallowHorizontalStretching;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisallowHorizontalSquishing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreZAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWarpRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMotionWarpRotationType RotationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WarpRotationTimeMultiplier;
    
    UAvaMotionWarpingModifierConfig_Warp();
    UFUNCTION(BlueprintCallable)
    static void AddRootMotionModifierSimpleWarp(FAvaRootMotionWarper& InMotionWarper, UAvaMotionWarpWindowFinder* InWindowFinder, const UAnimSequenceBase* InAnimation, float InStartTime, float InEndTime, FName InSyncPointName, bool bInWarpTranslation, bool bInDisallowHorizontalStretching, bool bInDisallowHorizontalSquishing, bool bInIgnoreZAxis, bool bInWarpRotation, EMotionWarpRotationType InRotationType, float InWarpRotationTimeMultiplier);
    
};

