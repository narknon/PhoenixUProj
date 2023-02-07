#pragma once
#include "CoreMinimal.h"
#include "PostProcessingFXCurve.h"
#include "PostProcessingMIDColorCurve.h"
#include "PostProcessingMIDScalarCurve.h"
#include "PostProcessingVarColorCurveWithKill.h"
#include "PostProcessingVarScalarCurveWithKill.h"
#include "PostProcessingFXCurveSet.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessingFXCurveSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostProcessingFXCurve> BlendCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostProcessingVarScalarCurveWithKill> PostProcessingScalarCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostProcessingVarColorCurveWithKill> PostProcessingColorCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostProcessingMIDScalarCurve> BlendableMaterialScalarCurves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostProcessingMIDColorCurve> BlendableMaterialColorCurves;
    
    PHOENIX_API FPostProcessingFXCurveSet();
};

