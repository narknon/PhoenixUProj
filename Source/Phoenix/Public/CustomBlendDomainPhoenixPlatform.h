#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainBase.h"
#include "CustomBlendDomainPhoenixPlatform.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UCustomBlendDomainPhoenixPlatform : public URenderSettingsCustomBlendDomainBase {
    GENERATED_BODY()
public:
    UCustomBlendDomainPhoenixPlatform();
};

