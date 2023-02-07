#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EPostProcessingVarScalar.h"
#include "PostProcessingVarScalarCurve.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessingVarScalarCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostProcessingVarScalar Var;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    RENDERSETTINGS_API FPostProcessingVarScalarCurve();
};

