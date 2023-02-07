#pragma once
#include "CoreMinimal.h"
#include "BoneIndexProperty.h"
#include "CurveIndexProperty.h"
#include "CurveNameProperty.h"
#include "IKTaskReferenceProperty.h"
#include "IKDriver_AnimationDrivenData.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FIKDriver_AnimationDrivenData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKTaskReferenceProperty Task;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneIndexProperty RotationTargetBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneIndexProperty TranslationTargetBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurveIndexProperty RotationWeightCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurveIndexProperty TranslationWeightCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurveNameProperty RotationWeightCurveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCurveNameProperty TranslationWeightCurveName;
    
    FIKDriver_AnimationDrivenData();
};

