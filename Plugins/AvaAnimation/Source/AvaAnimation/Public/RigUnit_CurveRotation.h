#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "RigUnit_CurveRotation_DebugSettings.h"
#include "RigUnit_CurveRotation_Target.h"
#include "RigUnit_CurveRotation_WorkData.h"
#include "Units/RigUnit.h"
#include "RigUnit_CurveRotation.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_CurveRotation : public FRigUnitMutable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LeafBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TrunkBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_CurveRotation_Target Primary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_CurveRotation_Target Secondary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRuntimeFloatCurve> PerBoneAngleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> PerBoneInterpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPropagateToChildren;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_CurveRotation_DebugSettings DebugSettings;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRigUnit_CurveRotation_WorkData WorkData;
    
public:
    AVAANIMATION_API FRigUnit_CurveRotation();
};

