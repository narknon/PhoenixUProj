#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainHDRLinearGamma.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainHDRLinearGamma : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainHDRLinearGamma();
};

