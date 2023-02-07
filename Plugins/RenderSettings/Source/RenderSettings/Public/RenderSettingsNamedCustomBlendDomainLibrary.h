#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomainBase.h"
#include "RenderSettingsNamedCustomBlendDomainLibrary.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsNamedCustomBlendDomainLibrary : public URenderSettingsNamedCustomBlendDomainBase {
    GENERATED_BODY()
public:
    URenderSettingsNamedCustomBlendDomainLibrary();
};

