#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStatesAndData.generated.h"

class UMaterialSwapMeshState;
class UMaterialSwapMeshStateData;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapMeshStatesAndData {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> States;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshStateData*> Data;
    
public:
    FMaterialSwapMeshStatesAndData();
};

