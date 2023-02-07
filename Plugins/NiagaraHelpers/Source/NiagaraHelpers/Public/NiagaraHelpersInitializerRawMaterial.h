#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializerRawMaterial.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerRawMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Value;
    
    FNiagaraHelpersInitializerRawMaterial();
};

