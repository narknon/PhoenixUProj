#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainFilteredOutdoors.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainFilteredOutdoors : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainFilteredOutdoors();
};

