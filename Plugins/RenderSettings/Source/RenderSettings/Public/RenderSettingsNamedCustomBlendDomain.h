#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomainBase.h"
#include "RenderSettingsNamedCustomBlendDomain.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsNamedCustomBlendDomain : public URenderSettingsNamedCustomBlendDomainBase {
    GENERATED_BODY()
public:
    URenderSettingsNamedCustomBlendDomain();
};

