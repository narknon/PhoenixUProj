#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateBoolMap.h"
#include "MaterialSwapMeshStateContactShadow.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateContactShadow : public UMaterialSwapMeshStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCastContactShadow;
    
    UMaterialSwapMeshStateContactShadow();
};

