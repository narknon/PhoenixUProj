#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainIndoorsBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainIndoorsBase : public URenderSettingsNamedCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainIndoorsBase();
};

