#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.h"
#include "NiagaraHelpersVarNameFloat.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarNameFloat : public FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    NIAGARAHELPERS_API FNiagaraHelpersVarNameFloat();
};

