#pragma once
#include "CoreMinimal.h"
#include "MeshArrayHolder.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FMeshArrayHolder {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> Meshes;
    
    PHOENIX_API FMeshArrayHolder();
};

