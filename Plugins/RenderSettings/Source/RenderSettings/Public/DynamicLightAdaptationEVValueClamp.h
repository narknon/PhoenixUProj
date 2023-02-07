#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationEVValue.h"
#include "DynamicLightAdaptationEVValueClamp.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FDynamicLightAdaptationEVValueClamp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicLightAdaptationEVValue MinEV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicLightAdaptationEVValue MaxEV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseMinEV: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseMaxEV: 1;
    
    FDynamicLightAdaptationEVValueClamp();
};

