#pragma once
#include "CoreMinimal.h"
#include "EBeaufortWindScale.h"
#include "WorldFXRuleWeatherWindSpeed.h"
#include "WorldFXRuleWeatherWindSpeedLessThan.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleWeatherWindSpeedLessThan : public UWorldFXRuleWeatherWindSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBeaufortWindScale Threshold;
    
    UWorldFXRuleWeatherWindSpeedLessThan();
};

