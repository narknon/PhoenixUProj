#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "ObjectFadeParamsCurve.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FObjectFadeParamsCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve RuntimeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ExternalCurve;
    
    FXUTIL_API FObjectFadeParamsCurve();
};

