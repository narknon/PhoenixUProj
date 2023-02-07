#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateIntMap.h"
#include "MeshStateLightingFeatures.h"
#include "MaterialSwapMeshStateLightingFeatures.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateLightingFeatures : public UMaterialSwapMeshStateIntMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMeshStateLightingFeatures LightingFeatures;
    
    UMaterialSwapMeshStateLightingFeatures();
};

