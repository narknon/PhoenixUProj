#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleWeatherWindSpeed.h"
#include "WorldFXRuleWeatherWindSpeedRangeMS.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleWeatherWindSpeedRangeMS : public UWorldFXRuleWeatherWindSpeed {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float minThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float maxThreshold;
    
    UWorldFXRuleWeatherWindSpeedRangeMS();
};

