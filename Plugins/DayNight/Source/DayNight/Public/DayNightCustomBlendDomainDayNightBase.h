#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainBase.h"
#include "DayNightCustomBlendDomainDayNightBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UDayNightCustomBlendDomainDayNightBase : public URenderSettingsCustomBlendDomainBase {
    GENERATED_BODY()
public:
    UDayNightCustomBlendDomainDayNightBase();
};

