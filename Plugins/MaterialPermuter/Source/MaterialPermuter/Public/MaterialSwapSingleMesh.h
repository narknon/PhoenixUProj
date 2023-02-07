#pragma once
#include "CoreMinimal.h"
#include "MaterialSwap.h"
#include "MaterialSwapMeshStatesAndData.h"
#include "MeshMaterialSwap.h"
#include "MaterialSwapSingleMesh.generated.h"

class UMeshComponent;

UCLASS(Blueprintable, NonTransient)
class MATERIALPERMUTER_API UMaterialSwapSingleMesh : public UMaterialSwap {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMeshComponent> Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMeshMaterialSwap SwappedMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapMeshStatesAndData MeshStates;
    
public:
    UMaterialSwapSingleMesh();
};

