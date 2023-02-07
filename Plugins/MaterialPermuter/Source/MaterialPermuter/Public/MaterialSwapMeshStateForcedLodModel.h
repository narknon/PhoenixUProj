#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateIntMap.h"
#include "MaterialSwapMeshStateForcedLodModel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateForcedLodModel : public UMaterialSwapMeshStateIntMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ForcedLodModel;
    
    UMaterialSwapMeshStateForcedLodModel();
};

