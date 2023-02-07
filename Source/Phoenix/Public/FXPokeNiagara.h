#pragma once
#include "CoreMinimal.h"
#include "FXPoke.h"
#include "PokeNiagaraFXBool.h"
#include "PokeNiagaraFXColor.h"
#include "PokeNiagaraFXFloat.h"
#include "PokeNiagaraFXInt.h"
#include "PokeNiagaraFXQuat.h"
#include "PokeNiagaraFXVector.h"
#include "PokeNiagaraFXVector4.h"
#include "FXPokeNiagara.generated.h"

USTRUCT(BlueprintType)
struct FFXPokeNiagara : public FFXPoke {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPokeNiagaraFXFloat> Floats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPokeNiagaraFXColor> Colors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPokeNiagaraFXVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPokeNiagaraFXVector4> Vector4s;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPokeNiagaraFXQuat> Quats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPokeNiagaraFXInt> Ints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPokeNiagaraFXBool> Bools;
    
    PHOENIX_API FFXPokeNiagara();
};

