#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshState.h"
#include "MaterialSwapMeshStateBoolMap.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapMeshStateBoolMap : public UMaterialSwapMeshState {
    GENERATED_BODY()
public:
    UMaterialSwapMeshStateBoolMap();
};

