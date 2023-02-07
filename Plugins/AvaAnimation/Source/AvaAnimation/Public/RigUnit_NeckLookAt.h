#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "RigUnit_NeckLookAt_BoneRotation.h"
#include "RigUnit_NeckLookAt_ConeConstraint.h"
#include "RigUnit_NeckLookAt_ConeConstraintBone.h"
#include "RigUnit_NeckLookAt_DebugSettings.h"
#include "RigUnit_NeckLookAt_SoftAngleLimits.h"
#include "RigUnit_NeckLookAt_Target.h"
#include "RigUnit_NeckLookAt_WorkData.h"
#include "Units/RigUnit.h"
#include "RigUnit_NeckLookAt.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_NeckLookAt : public FRigUnitMutable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EffectorBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StartBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator SpaceRotationSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator BaseBoneRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRigUnit_NeckLookAt_BoneRotation> BoneRotations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_NeckLookAt_Target Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpineMobility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve YawWeightCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve PitchWeightCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve PitchFromYawWeightCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_NeckLookAt_SoftAngleLimits InputYawMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_NeckLookAt_SoftAngleLimits InputPitchMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyConstraints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_NeckLookAt_ConeConstraint BaseConstraint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRigUnit_NeckLookAt_ConeConstraintBone> BoneConstraints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_NeckLookAt_DebugSettings DebugSettings;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRigUnit_NeckLookAt_WorkData WorkData;
    
public:
    AVAANIMATION_API FRigUnit_NeckLookAt();
};

