#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateBoolMap.h"
#include "MaterialSwapMeshStateTag.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateTag : public UMaterialSwapMeshStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    UMaterialSwapMeshStateTag();
};

