#pragma once
#include "CoreMinimal.h"
#include "RigUnit_SpineWarp_CounterRotateBone.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_SpineWarp_CounterRotateBone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneToCounterRotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAngle;
    
    AVAANIMATION_API FRigUnit_SpineWarp_CounterRotateBone();
};

