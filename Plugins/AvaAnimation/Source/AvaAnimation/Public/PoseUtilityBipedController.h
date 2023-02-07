#pragma once
#include "CoreMinimal.h"
#include "BoneContainer.h"
#include "PoseUtilityIK.h"
#include "PoseUtilityRFK.h"
#include "PoseUtilityBipedController.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FPoseUtilityBipedController {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReference Pelvis;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReference PelvisTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseUtilityIK RightLeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseUtilityIK LeftLeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseUtilityRFK Spine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseUtilityIK RightArm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseUtilityIK LeftArm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseUtilityRFK Neck;
    
    FPoseUtilityBipedController();
};

