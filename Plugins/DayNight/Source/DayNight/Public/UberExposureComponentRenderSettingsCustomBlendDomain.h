#pragma once
#include "CoreMinimal.h"
#include "UberExposureComponentConstDriver.h"
#include "UberExposureComponentRenderSettingsCustomBlendDomain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UUberExposureComponentRenderSettingsCustomBlendDomain : public UUberExposureComponentConstDriver {
    GENERATED_BODY()
public:
    UUberExposureComponentRenderSettingsCustomBlendDomain();
};

