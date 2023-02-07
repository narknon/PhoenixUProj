#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "DayNightCustomBlendDomainDay.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UDayNightCustomBlendDomainDay : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UDayNightCustomBlendDomainDay();
};

