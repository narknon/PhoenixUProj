#pragma once
#include "CoreMinimal.h"

#include "LookLimits.h"
#include "RigUnit_IncrementalRotation_DebugSettings.h"
#include "RigUnit_IncrementalRotation_WorkData.h"
#include "RigUnit_WB_AimBone_Target.h"
#include "Math/ControlRigMathLibrary.h"
#include "Units/RigUnit.h"
#include "RigUnit_IncrementalRotation.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_IncrementalRotation : public FRigUnitMutable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LeafBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TrunkBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_WB_AimBone_Target Primary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_WB_AimBone_Target Secondary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLookLimits> LookLimits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Blending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EControlRigAnimEasingType RotationEaseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPropagateToChildren;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_IncrementalRotation_DebugSettings DebugSettings;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRigUnit_IncrementalRotation_WorkData WorkData;
    
public:
    AVAANIMATION_API FRigUnit_IncrementalRotation();
};

