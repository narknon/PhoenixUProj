#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "EPostProcessingVarColor.h"
#include "PostProcessingVarColorCurve.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessingVarColorCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostProcessingVarColor Var;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Curve;
    
    RENDERSETTINGS_API FPostProcessingVarColorCurve();
};

