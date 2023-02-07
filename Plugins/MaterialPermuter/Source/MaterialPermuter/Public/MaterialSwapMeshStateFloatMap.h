#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshState.h"
#include "MaterialSwapMeshStateFloatMap.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialSwapMeshStateFloatMap : public UMaterialSwapMeshState {
    GENERATED_BODY()
public:
    UMaterialSwapMeshStateFloatMap();
};

