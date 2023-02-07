#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateBoolMap.h"
#include "MaterialSwapMeshStateReceivesDecals.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateReceivesDecals : public UMaterialSwapMeshStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReceivesDecals;
    
    UMaterialSwapMeshStateReceivesDecals();
};

