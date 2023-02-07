#pragma once
#include "CoreMinimal.h"
#include "FXPoke.h"
#include "PokeNiagaraFXParameter.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXParameter : public FFXPoke {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    PHOENIX_API FPokeNiagaraFXParameter();
};

