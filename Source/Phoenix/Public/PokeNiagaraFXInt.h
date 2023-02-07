#pragma once
#include "CoreMinimal.h"
#include "PokeNiagaraFXParameter.h"
#include "PokeNiagaraFXInt.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXInt : public FPokeNiagaraFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    PHOENIX_API FPokeNiagaraFXInt();
};

