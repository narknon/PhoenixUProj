#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "PostProcessingMIDColorCurve.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessingMIDColorCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Blendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FPostProcessingMIDColorCurve();
};

