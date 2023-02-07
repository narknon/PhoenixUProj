#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.h"
#include "NiagaraHelpersVarNameVector.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarNameVector : public FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    NIAGARAHELPERS_API FNiagaraHelpersVarNameVector();
};

