#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainBase.h"
#include "RenderSettingsCustomBlendDomainProbeIndoorsBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainProbeIndoorsBase : public URenderSettingsCustomBlendDomainBase {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainProbeIndoorsBase();
};

