#pragma once
#include "CoreMinimal.h"
#include "MeshSwappedMaterial.h"
#include "MeshMaterialSwap.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMeshMaterialSwap {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMeshSwappedMaterial> SwappedMaterials;
    
public:
    FMeshMaterialSwap();
};

