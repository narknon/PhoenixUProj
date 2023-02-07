#pragma once
#include "CoreMinimal.h"
#include "BoneReferenceEx.h"
#include "IKDriver_LedgeContactHipsControl.generated.h"

USTRUCT(BlueprintType)
struct FIKDriver_LedgeContactHipsControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AlphaVariableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetTransformVariableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReferenceEx BoneReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRotationAngleAwayFromWall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistanceFromWall;
    
    AVAANIMATION_API FIKDriver_LedgeContactHipsControl();
};

