#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "SkinFXExternalContext.generated.h"

class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct FSkinFXExternalContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FXName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TimeFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters Values;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMeshStatesSet;
    
    SKINFX_API FSkinFXExternalContext();
};

