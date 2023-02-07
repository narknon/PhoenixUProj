#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsInLevelBase.h"
#include "DynamicLightAdaptationModSettingsInLevelNightOnly.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDynamicLightAdaptationModSettingsInLevelNightOnly : public UDynamicLightAdaptationModSettingsInLevelBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EVAmount;
    
    UDynamicLightAdaptationModSettingsInLevelNightOnly();
};

