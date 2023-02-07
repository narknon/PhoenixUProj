#pragma once
#include "CoreMinimal.h"
#include "PokeNiagaraFXParameter.h"
#include "PokeNiagaraFXFloat.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXFloat : public FPokeNiagaraFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    PHOENIX_API FPokeNiagaraFXFloat();
};

