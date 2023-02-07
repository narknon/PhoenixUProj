#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MaterialSwapInfoObjectBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapInfoObjectBase : public UObject {
    GENERATED_BODY()
public:
    UMaterialSwapInfoObjectBase();
};

