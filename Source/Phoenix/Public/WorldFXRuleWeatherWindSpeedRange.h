#pragma once
#include "CoreMinimal.h"
#include "EBeaufortWindScale.h"
#include "WorldFXRuleWeatherWindSpeed.h"
#include "WorldFXRuleWeatherWindSpeedRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleWeatherWindSpeedRange : public UWorldFXRuleWeatherWindSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBeaufortWindScale minThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBeaufortWindScale maxThreshold;
    
    UWorldFXRuleWeatherWindSpeedRange();
};

