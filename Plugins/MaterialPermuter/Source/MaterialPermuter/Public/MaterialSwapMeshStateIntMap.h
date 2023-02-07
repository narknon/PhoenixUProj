#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshState.h"
#include "MaterialSwapMeshStateIntMap.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapMeshStateIntMap : public UMaterialSwapMeshState {
    GENERATED_BODY()
public:
    UMaterialSwapMeshStateIntMap();
};

