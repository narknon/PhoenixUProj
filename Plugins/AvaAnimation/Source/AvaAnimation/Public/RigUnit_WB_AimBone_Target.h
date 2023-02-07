#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EOrientationTargetKind.h"
#include "RigUnit_WB_AimBone_Target.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_WB_AimBone_Target {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Axis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOrientationTargetKind Kind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Space;
    
    AVAANIMATION_API FRigUnit_WB_AimBone_Target();
};

