#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainFadeToBlack.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URenderSettingsCustomBlendDomainFadeToBlack : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainFadeToBlack();
};

