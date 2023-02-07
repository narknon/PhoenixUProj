#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableBase.h"
#include "GlobalLightingBlendable.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendable : public UGlobalLightingBlendableBase {
    GENERATED_BODY()
public:
    UGlobalLightingBlendable();
};

