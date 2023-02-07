#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateData.h"
#include "MaterialSwapMeshStateStencilManagerLockStencilCustomDepthData.generated.h"

class AStencilManagerSingleton;

UCLASS(Blueprintable, NonTransient)
class UMaterialSwapMeshStateStencilManagerLockStencilCustomDepthData : public UMaterialSwapMeshStateData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AStencilManagerSingleton> StencilManagerSingleton;
    
    UMaterialSwapMeshStateStencilManagerLockStencilCustomDepthData();
};

