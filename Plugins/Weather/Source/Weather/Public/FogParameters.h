#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParametersOverride.h"
#include "FogParameters.generated.h"

USTRUCT(BlueprintType)
struct FFogParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParametersOverride Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollowCamera;
    
    WEATHER_API FFogParameters();
};

