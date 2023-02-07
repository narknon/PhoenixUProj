#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EFXUpdatePostProcessingCurveParameter.h"
#include "PostProcessingFXCurve.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessingFXCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFXUpdatePostProcessingCurveParameter Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FPostProcessingFXCurve();
};

