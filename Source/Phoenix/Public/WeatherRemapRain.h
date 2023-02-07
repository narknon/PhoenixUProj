#pragma once
#include "CoreMinimal.h"
#include "WeatherRemapBase.h"
#include "WeatherRemapRain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWeatherRemapRain : public UWeatherRemapBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VfxThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SfxThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactThreshold;
    
    UWeatherRemapRain();
};

