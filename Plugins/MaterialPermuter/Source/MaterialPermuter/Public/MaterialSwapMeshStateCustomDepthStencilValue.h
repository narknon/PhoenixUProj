#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateIntMap.h"
#include "MaterialSwapMeshStateCustomDepthStencilValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateCustomDepthStencilValue : public UMaterialSwapMeshStateIntMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CustomDepthStencilValue;
    
    UMaterialSwapMeshStateCustomDepthStencilValue();
};

