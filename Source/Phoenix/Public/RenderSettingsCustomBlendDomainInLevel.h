#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainInLevel.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class URenderSettingsCustomBlendDomainInLevel : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainInLevel();
};

