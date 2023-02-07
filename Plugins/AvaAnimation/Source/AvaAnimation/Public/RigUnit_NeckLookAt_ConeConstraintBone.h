#pragma once
#include "CoreMinimal.h"
#include "RigUnit_NeckLookAt_ConeConstraint.h"
#include "RigUnit_NeckLookAt_ConeConstraintBone.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_NeckLookAt_ConeConstraintBone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigUnit_NeckLookAt_ConeConstraint Constraint;
    
    AVAANIMATION_API FRigUnit_NeckLookAt_ConeConstraintBone();
};

