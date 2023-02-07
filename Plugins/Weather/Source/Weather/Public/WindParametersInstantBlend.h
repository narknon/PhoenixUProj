#pragma once
#include "CoreMinimal.h"
#include "WindParametersInstant.h"
#include "WindParametersInstantBlend.generated.h"

USTRUCT(BlueprintType)
struct FWindParametersInstantBlend : public FWindParametersInstant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Blend;
    
    WEATHER_API FWindParametersInstantBlend();
};

