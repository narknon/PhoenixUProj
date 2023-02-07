#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControlRigConeConstraint.generated.h"

USTRUCT(BlueprintType)
struct FControlRigConeConstraint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RollLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator ConeRotation;
    
    AVAANIMATION_API FControlRigConeConstraint();
};

