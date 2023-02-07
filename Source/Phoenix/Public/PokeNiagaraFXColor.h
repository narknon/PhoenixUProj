#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PokeNiagaraFXParameter.h"
#include "PokeNiagaraFXColor.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXColor : public FPokeNiagaraFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    PHOENIX_API FPokeNiagaraFXColor();
};

