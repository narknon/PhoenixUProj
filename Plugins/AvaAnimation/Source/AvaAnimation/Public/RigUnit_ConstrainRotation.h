#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControlRigConeConstraint.h"
#include "RigUnit_ConstrainRotation_DebugSettings.h"
#include "RigUnit_ConstrainRotation_WorkData.h"
#include "Units/RigUnit.h"
#include "RigUnit_ConstrainRotation.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_ConstrainRotation : public FRigUnitMutable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator LocalRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlRigConeConstraint ConeConstraint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_ConstrainRotation_DebugSettings DebugSettings;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRigUnit_ConstrainRotation_WorkData WorkData;
    
public:
    AVAANIMATION_API FRigUnit_ConstrainRotation();
};

