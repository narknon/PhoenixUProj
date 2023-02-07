#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapPriority.h"
#include "MaterialPermuterKey.h"
#include "MaterialSwapKeyBase.h"
#include "MaterialSwapRules.h"
#include "MaterialSwapKey.generated.h"

class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapKey : public FMaterialSwapKeyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKey Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    FMaterialSwapKey();
};

