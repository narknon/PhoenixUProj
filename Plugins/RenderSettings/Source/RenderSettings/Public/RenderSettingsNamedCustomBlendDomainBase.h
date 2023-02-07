#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsNamedCustomBlendDomainBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsNamedCustomBlendDomainBase : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsNamedCustomBlendDomainBase();
};

