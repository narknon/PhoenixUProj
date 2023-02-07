#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableModsBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableModsBase : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UGlobalLightingBlendableModsBase();
};

