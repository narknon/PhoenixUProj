#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainPaused.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainPaused : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainPaused();
};

