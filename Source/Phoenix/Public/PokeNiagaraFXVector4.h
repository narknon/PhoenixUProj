#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PokeNiagaraFXParameter.h"
#include "PokeNiagaraFXVector4.generated.h"

USTRUCT(BlueprintType)
struct FPokeNiagaraFXVector4 : public FPokeNiagaraFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 Vector;
    
    PHOENIX_API FPokeNiagaraFXVector4();
};

