#pragma once
#include "CoreMinimal.h"
#include "RigUnit_NeckLookAt_SoftAngleLimits.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_NeckLookAt_SoftAngleLimits {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinInputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxInputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxOutputAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoosenessFactor;
    
    AVAANIMATION_API FRigUnit_NeckLookAt_SoftAngleLimits();
};

