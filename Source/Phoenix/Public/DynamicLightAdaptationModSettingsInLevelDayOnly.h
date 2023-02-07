#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsInLevelBase.h"
#include "DynamicLightAdaptationModSettingsInLevelDayOnly.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDynamicLightAdaptationModSettingsInLevelDayOnly : public UDynamicLightAdaptationModSettingsInLevelBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EVAmount;
    
    UDynamicLightAdaptationModSettingsInLevelDayOnly();
};

