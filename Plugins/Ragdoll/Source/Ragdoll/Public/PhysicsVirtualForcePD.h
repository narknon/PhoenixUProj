#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EPhysicsVirtualForceApplication.h"
#include "PhysicsPD.h"
#include "PhysicsVirtualForcePD.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsVirtualForcePD {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhysicsPD PD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ForceLocationLocal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityCompensation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Depth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhysicsVirtualForceApplication Application;
    
    RAGDOLL_API FPhysicsVirtualForcePD();
};

