#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainNoPreCompute : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainNoPreCompute();
};

