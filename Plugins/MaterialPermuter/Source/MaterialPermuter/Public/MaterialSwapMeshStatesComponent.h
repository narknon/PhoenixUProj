#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStatesBaseComponent.h"
#include "MaterialSwapMeshStatesComponent.generated.h"

class UMaterialSwapMeshState;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialSwapMeshStatesComponent : public UMaterialSwapMeshStatesBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeChildren;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateOnTick;
    
    UMaterialSwapMeshStatesComponent();
};

