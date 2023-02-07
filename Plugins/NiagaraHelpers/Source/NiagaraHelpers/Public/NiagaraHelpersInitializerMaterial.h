#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarNameMaterial.h"
#include "NiagaraHelpersInitializerMaterial.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersVarNameMaterial Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Value;
    
    FNiagaraHelpersInitializerMaterial();
};

