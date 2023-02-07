#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "DayNightCustomBlendDomainNight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UDayNightCustomBlendDomainNight : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UDayNightCustomBlendDomainNight();
};

