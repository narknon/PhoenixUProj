#pragma once
#include "CoreMinimal.h"
#include "AnimMaskBoneReference.h"
#include "AnimMaskCurveReference.h"
#include "AnimMaskAssetIO.generated.h"

class UAnimMaskAsset;
class USkeleton;

USTRUCT(BlueprintType)
struct FAnimMaskAssetIO {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeleton* Skeleton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMaskAsset* ParentMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FAnimMaskBoneReference, float> BoneMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FAnimMaskCurveReference, float> CurveMask;
    
    AVAANIMATION_API FAnimMaskAssetIO();
};

