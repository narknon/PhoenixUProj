#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "InstancedTrailMemberScale.generated.h"

USTRUCT(BlueprintType)
struct FInstancedTrailMemberScale {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomizePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScaleCurve;
    
    PHOENIX_API FInstancedTrailMemberScale();
};

