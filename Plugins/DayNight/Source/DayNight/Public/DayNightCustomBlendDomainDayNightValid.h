#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "DayNightCustomBlendDomainDayNightValid.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UDayNightCustomBlendDomainDayNightValid : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UDayNightCustomBlendDomainDayNightValid();
};

