#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshState.h"
#include "MaterialSwapMeshStateStencilManagerLockStencilCustomDepth.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateStencilManagerLockStencilCustomDepth : public UMaterialSwapMeshState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderCustomDepth;
    
    UMaterialSwapMeshStateStencilManagerLockStencilCustomDepth();
};

