#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "DayNightCustomBlendDomainDayNightMoonDiskVisibility.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UDayNightCustomBlendDomainDayNightMoonDiskVisibility : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UDayNightCustomBlendDomainDayNightMoonDiskVisibility();
};

