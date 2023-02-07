#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateBoolMap.h"
#include "MaterialSwapMeshStateSelfShadowOnly.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateSelfShadowOnly : public UMaterialSwapMeshStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSelfShadowOnly;
    
    UMaterialSwapMeshStateSelfShadowOnly();
};

