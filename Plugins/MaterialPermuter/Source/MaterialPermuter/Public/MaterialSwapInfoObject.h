#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoObjectBase.h"
#include "MaterialSwapInfoObject.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapInfoObject : public UMaterialSwapInfoObjectBase {
    GENERATED_BODY()
public:
    UMaterialSwapInfoObject();
};

