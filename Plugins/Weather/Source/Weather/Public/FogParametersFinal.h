#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParameters.h"
#include "FogParametersFinal.generated.h"

USTRUCT(BlueprintType)
struct FFogParametersFinal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParameters Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollowCamera;
    
    WEATHER_API FFogParametersFinal();
};

