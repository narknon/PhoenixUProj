#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapPriority.h"
#include "MaterialPermuterKeyProperty.h"
#include "MaterialSwapKeyBase.h"
#include "MaterialSwapRules.h"
#include "MaterialSwapKeyUI.generated.h"

class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapKeyUI : public FMaterialSwapKeyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKeyProperty Permutation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    FMaterialSwapKeyUI();
};

