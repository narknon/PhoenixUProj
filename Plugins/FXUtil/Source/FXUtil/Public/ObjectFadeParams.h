#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EObjectFadeDirection.h"
#include "ObjectFadeParams.generated.h"

USTRUCT(BlueprintType)
struct FObjectFadeParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectFadeDirection Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve OpacityCurve;
    
    FXUTIL_API FObjectFadeParams();
};

