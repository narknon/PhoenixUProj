#pragma once
#include "CoreMinimal.h"
#include "PhysicsPD.h"
#include "PhysicsForceAndTorquePD.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsForceAndTorquePD {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhysicsPD VerticalForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhysicsPD HorizontalForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhysicsPD Torque;
    
    RAGDOLL_API FPhysicsForceAndTorquePD();
};

