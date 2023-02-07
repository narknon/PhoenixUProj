#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainFilteredProbeIndoors.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainFilteredProbeIndoors : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainFilteredProbeIndoors();
};

