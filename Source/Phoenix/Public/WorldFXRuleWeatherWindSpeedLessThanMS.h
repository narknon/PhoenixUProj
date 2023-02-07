#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleWeatherWindSpeed.h"
#include "WorldFXRuleWeatherWindSpeedLessThanMS.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleWeatherWindSpeedLessThanMS : public UWorldFXRuleWeatherWindSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UWorldFXRuleWeatherWindSpeedLessThanMS();
};

