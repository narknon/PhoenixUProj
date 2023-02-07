#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterParameterCopy.h"
#include "EMaterialSwapInfoTyoe.h"
#include "EMaterialSwapPriority.h"
#include "MaterialSwapInfoBase.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapRules.h"
#include "MaterialSwapInfo.generated.h"

class UMaterialInterface;
class UMaterialSwapMeshState;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapInfo : public FMaterialSwapInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapInfoTyoe SwapType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Group;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* MaterialOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> MaterialOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterParameterCopy ParameterCopy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters InitialParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwapMeshState*> MeshStates;
    
    FMaterialSwapInfo();
};

