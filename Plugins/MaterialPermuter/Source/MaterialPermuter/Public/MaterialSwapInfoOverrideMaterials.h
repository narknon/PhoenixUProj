#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterParameterCopy.h"
#include "EMaterialSwapPriority.h"
#include "MaterialSwapInfoBase.h"
#include "MaterialSwapRules.h"
#include "MaterialSwapInfoOverrideMaterials.generated.h"

class UMaterialInterface;
class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapInfoOverrideMaterials : public FMaterialSwapInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> MaterialOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterParameterCopy ParameterCopy;
    
    FMaterialSwapInfoOverrideMaterials();
};

