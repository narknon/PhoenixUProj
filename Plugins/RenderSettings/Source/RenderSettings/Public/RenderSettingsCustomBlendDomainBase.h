#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RenderSettingsCustomBlendDomainBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainBase : public UObject {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainBase();
};

