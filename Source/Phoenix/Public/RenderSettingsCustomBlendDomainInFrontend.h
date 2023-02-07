#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainInLevel.h"
#include "RenderSettingsCustomBlendDomainInFrontend.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URenderSettingsCustomBlendDomainInFrontend : public URenderSettingsCustomBlendDomainInLevel {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainInFrontend();
};

