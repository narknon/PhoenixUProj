#pragma once
#include "CoreMinimal.h"
#include "BlueprintMaterialSwapMeshStates.generated.h"

class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FBlueprintMaterialSwapMeshStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    FBlueprintMaterialSwapMeshStates();
};

