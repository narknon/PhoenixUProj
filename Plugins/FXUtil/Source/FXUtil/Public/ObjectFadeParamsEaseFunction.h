#pragma once
#include "CoreMinimal.h"
#include "EObjectFadeDirection.h"
#include "EasingFunction.h"
#include "ObjectFadeParamsEaseFunction.generated.h"

USTRUCT(BlueprintType)
struct FObjectFadeParamsEaseFunction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectFadeDirection Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEasingFunction EaseFunction;
    
    FXUTIL_API FObjectFadeParamsEaseFunction();
};

