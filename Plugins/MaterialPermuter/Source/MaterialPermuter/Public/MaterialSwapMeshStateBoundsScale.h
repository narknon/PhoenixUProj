#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateFloatMap.h"
#include "MaterialSwapMeshStateBoundsScale.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateBoundsScale : public UMaterialSwapMeshStateFloatMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoundsScale;
    
    UMaterialSwapMeshStateBoundsScale();
};

