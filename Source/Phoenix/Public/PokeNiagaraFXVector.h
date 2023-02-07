#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PokeNiagaraFXParameter.h"
#include "PokeNiagaraFXVector.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXVector : public FPokeNiagaraFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Vector;
    
    PHOENIX_API FPokeNiagaraFXVector();
};

