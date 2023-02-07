#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainHDR.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainHDR : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainHDR();
};

