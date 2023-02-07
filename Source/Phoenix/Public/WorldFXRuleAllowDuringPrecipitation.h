#pragma once
#include "CoreMinimal.h"
#include "WorldFXRulePrecipitation.h"
#include "WorldFXRuleAllowDuringPrecipitation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleAllowDuringPrecipitation : public UWorldFXRulePrecipitation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AllowDuringPrecipitation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AllowDuringTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCoverageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxIntensityThreshold;
    
    UWorldFXRuleAllowDuringPrecipitation();
};

