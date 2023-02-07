#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightingBlendableBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableBase : public UObject {
    GENERATED_BODY()
public:
    UGlobalLightingBlendableBase();
};

