#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MaterialSwapMeshState.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapMeshState : public UObject {
    GENERATED_BODY()
public:
    UMaterialSwapMeshState();
};

