#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogSecondParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FExpHeightFogSecondParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogHeightFalloff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogHeightOffset;
    
    FExpHeightFogSecondParameters();
};

