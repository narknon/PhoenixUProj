#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateBoolMap.h"
#include "MaterialSwapMeshStateRenderCustomDepth.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateRenderCustomDepth : public UMaterialSwapMeshStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderCustomDepth;
    
    UMaterialSwapMeshStateRenderCustomDepth();
};

