#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.h"
#include "NiagaraHelpersVarNameQuat.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarNameQuat : public FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    NIAGARAHELPERS_API FNiagaraHelpersVarNameQuat();
};

