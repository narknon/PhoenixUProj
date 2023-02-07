#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "DayNightCustomBlendDomainDayNightComputeOnly.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UDayNightCustomBlendDomainDayNightComputeOnly : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UDayNightCustomBlendDomainDayNightComputeOnly();
};

