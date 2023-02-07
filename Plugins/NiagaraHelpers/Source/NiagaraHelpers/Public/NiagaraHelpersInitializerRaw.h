#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializerRawBool.h"
#include "NiagaraHelpersInitializerRawFloat.h"
#include "NiagaraHelpersInitializerRawInteger.h"
#include "NiagaraHelpersInitializerRawLinearColor.h"
#include "NiagaraHelpersInitializerRawMaterial.h"
#include "NiagaraHelpersInitializerRawRotator.h"
#include "NiagaraHelpersInitializerRawVector.h"
#include "NiagaraHelpersInitializerRaw.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerRaw {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRawFloat> Floats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRawBool> Bools;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRawInteger> Integers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRawLinearColor> LinearColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRawVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRawRotator> Rotators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersInitializerRawMaterial> Materials;
    
    FNiagaraHelpersInitializerRaw();
};

