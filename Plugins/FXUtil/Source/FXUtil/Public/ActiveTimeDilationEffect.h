#pragma once
#include "CoreMinimal.h"
#include "ActiveTimeDilationEffect.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FActiveTimeDilationEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TimeDilationCurve;
    
    FXUTIL_API FActiveTimeDilationEffect();
};

