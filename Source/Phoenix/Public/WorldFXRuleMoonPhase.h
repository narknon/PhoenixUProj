#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleNightDay.h"
#include "WorldFXRuleMoonPhase.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleMoonPhase : public UWorldFXRuleNightDay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MoonPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyAtNight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NightThreshold;
    
    UWorldFXRuleMoonPhase();
};

