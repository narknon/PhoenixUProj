#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterParameterCopy.h"
#include "MaterialPermuterKey.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialPermuterHardSwapBase.generated.h"

class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterHardSwapBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKey Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParametersSimple Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterParameterCopy ParameterCopy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableMIDSharing;
    
    FMaterialPermuterHardSwapBase();
};

