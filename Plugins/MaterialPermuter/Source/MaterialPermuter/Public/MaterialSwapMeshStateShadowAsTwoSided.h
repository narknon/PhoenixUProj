#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateBoolMap.h"
#include "MaterialSwapMeshStateShadowAsTwoSided.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateShadowAsTwoSided : public UMaterialSwapMeshStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCastShadowAsTwoSided;
    
    UMaterialSwapMeshStateShadowAsTwoSided();
};

