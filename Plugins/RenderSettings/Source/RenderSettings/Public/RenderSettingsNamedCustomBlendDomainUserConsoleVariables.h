#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomainLibrary.h"
#include "RenderSettingsNamedCustomBlendDomainUserConsoleVariables.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsNamedCustomBlendDomainUserConsoleVariables : public URenderSettingsNamedCustomBlendDomainLibrary {
    GENERATED_BODY()
public:
    URenderSettingsNamedCustomBlendDomainUserConsoleVariables();
};

