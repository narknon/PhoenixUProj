#pragma once
#include "CoreMinimal.h"
#include "PhysicsVirtualForcePD.h"
#include "PhysicsPoseDrivingConfig.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsPoseDrivingConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FPhysicsVirtualForcePD> VirtualForces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityCompensation;
    
    RAGDOLL_API FPhysicsPoseDrivingConfig();
};

