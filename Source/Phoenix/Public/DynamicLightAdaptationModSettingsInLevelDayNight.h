#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsInLevelBase.h"
#include "DynamicLightAdaptationModSettingsInLevelDayNight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDynamicLightAdaptationModSettingsInLevelDayNight : public UDynamicLightAdaptationModSettingsInLevelBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DayEVAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NightEVAmount;
    
    UDynamicLightAdaptationModSettingsInLevelDayNight();
};

