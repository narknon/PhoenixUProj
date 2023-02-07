#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpingModifier.h"
#include "AvaMotionWarpingSyncPoint.h"
#include "EMotionWarpRotationType.h"
#include "AvaMotionWarpingModifier_Warp.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FAvaMotionWarpingModifier_Warp : public FAvaMotionWarpingModifier {
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvaMotionWarpingSyncPoint CachedSyncPoint;
    
    FAvaMotionWarpingModifier_Warp();
};

