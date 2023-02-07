#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MaterialPermuterDynamicTrigger.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class MATERIALPERMUTER_API UMaterialPermuterDynamicTrigger : public UObject {
    GENERATED_BODY()
public:
    UMaterialPermuterDynamicTrigger();
};

