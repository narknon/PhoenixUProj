#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimMask.h"
#include "AnimMaskBoneReference.h"
#include "AnimMaskCurveReference.h"
#include "AnimMaskAsset.generated.h"

class UAnimMaskAsset;
class USkeleton;

UCLASS(Blueprintable)
class AVAANIMATION_API UAnimMaskAsset : public UObject, public IAnimMask {
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
    
    UAnimMaskAsset();
    
    // Fix for true pure virtual functions not being implemented
};

