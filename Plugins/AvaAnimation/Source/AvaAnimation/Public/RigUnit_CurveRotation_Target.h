#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EOrientationTargetKind2.h"
#include "RigUnit_CurveRotation_Target.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_CurveRotation_Target {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOrientationTargetKind2 Kind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Space;
    
    AVAANIMATION_API FRigUnit_CurveRotation_Target();
};

