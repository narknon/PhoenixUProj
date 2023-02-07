#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsInLevelBase.h"
#include "DynamicLightAdaptationModSettingsInLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDynamicLightAdaptationModSettingsInLevel : public UDynamicLightAdaptationModSettingsInLevelBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EVAmount;
    
    UDynamicLightAdaptationModSettingsInLevel();
};

