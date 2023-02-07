#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PokeNiagaraFXParameter.h"
#include "PokeNiagaraFXQuat.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXQuat : public FPokeNiagaraFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Rotator;
    
    PHOENIX_API FPokeNiagaraFXQuat();
};

