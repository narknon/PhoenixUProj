#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleNightDay.h"
#include "WorldFXRuleNightDayThreshold.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleNightDayThreshold : public UWorldFXRuleNightDay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float minThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float maxThreshold;
    
    UWorldFXRuleNightDayThreshold();
};

