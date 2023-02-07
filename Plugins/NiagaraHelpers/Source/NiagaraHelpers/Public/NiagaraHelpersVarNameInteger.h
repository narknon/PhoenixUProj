#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.h"
#include "NiagaraHelpersVarNameInteger.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarNameInteger : public FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    NIAGARAHELPERS_API FNiagaraHelpersVarNameInteger();
};

