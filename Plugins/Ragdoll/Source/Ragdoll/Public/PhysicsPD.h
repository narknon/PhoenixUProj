#pragma once
#include "CoreMinimal.h"
#include "PhysicsPD.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsPD {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Stiffness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Damping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Max;
    
    RAGDOLL_API FPhysicsPD();
};

