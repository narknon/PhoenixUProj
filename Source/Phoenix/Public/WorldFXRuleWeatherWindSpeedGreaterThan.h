#pragma once
#include "CoreMinimal.h"
#include "EBeaufortWindScale.h"
#include "WorldFXRuleWeatherWindSpeed.h"
#include "WorldFXRuleWeatherWindSpeedGreaterThan.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleWeatherWindSpeedGreaterThan : public UWorldFXRuleWeatherWindSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBeaufortWindScale Threshold;
    
    UWorldFXRuleWeatherWindSpeedGreaterThan();
};

