#pragma once
#include "CoreMinimal.h"
#include "WorldFXRulePrecipitation.h"
#include "WorldFXRuleNoPrecipitation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleNoPrecipitation : public UWorldFXRulePrecipitation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCoverageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxIntensityThreshold;
    
    UWorldFXRuleNoPrecipitation();
};

