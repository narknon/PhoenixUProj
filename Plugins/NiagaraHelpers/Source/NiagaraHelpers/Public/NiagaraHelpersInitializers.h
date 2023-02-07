#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializerBool.h"
#include "NiagaraHelpersInitializerFloat.h"
#include "NiagaraHelpersInitializerInteger.h"
#include "NiagaraHelpersInitializerLinearColor.h"
#include "NiagaraHelpersInitializerMaterial.h"
#include "NiagaraHelpersInitializerRotator.h"
#include "NiagaraHelpersInitializerVector.h"
#include "NiagaraHelpersInitializers.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerFloat> Floats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerBool> Bools;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerInteger> Integers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerLinearColor> LinearColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRotator> Rotators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerMaterial> Materials;
    
    FNiagaraHelpersInitializers();
};

