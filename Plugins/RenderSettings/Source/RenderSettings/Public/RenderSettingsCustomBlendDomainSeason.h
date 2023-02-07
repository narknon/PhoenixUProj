#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainBase.h"
#include "RenderSettingsCustomBlendDomainSeason.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainSeason : public URenderSettingsCustomBlendDomainBase {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainSeason();
};

