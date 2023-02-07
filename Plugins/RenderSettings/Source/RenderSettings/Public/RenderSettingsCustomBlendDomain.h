#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainBase.h"
#include "RenderSettingsCustomBlendDomain.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomain : public URenderSettingsCustomBlendDomainBase {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomain();
};

