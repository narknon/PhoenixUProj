#pragma once
#include "CoreMinimal.h"
#include "EDynamicLightAdaptationEVValueType.h"
#include "DynamicLightAdaptationEVValue.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FDynamicLightAdaptationEVValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDynamicLightAdaptationEVValueType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EVValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMaxTarget;
    
    FDynamicLightAdaptationEVValue();
};

