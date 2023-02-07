#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateTag.h"
#include "MaterialSwapMeshStateRemoveTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateRemoveTag : public UMaterialSwapMeshStateTag {
    GENERATED_BODY()
public:
    UMaterialSwapMeshStateRemoveTag();
};

