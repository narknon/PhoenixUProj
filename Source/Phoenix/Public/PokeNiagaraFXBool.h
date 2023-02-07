#pragma once
#include "CoreMinimal.h"
#include "PokeNiagaraFXParameter.h"
#include "PokeNiagaraFXBool.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXBool : public FPokeNiagaraFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValue;
    
    PHOENIX_API FPokeNiagaraFXBool();
};

