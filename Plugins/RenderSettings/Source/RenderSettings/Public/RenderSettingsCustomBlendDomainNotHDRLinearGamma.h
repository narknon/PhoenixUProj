#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainNotHDRLinearGamma.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainNotHDRLinearGamma : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainNotHDRLinearGamma();
};

