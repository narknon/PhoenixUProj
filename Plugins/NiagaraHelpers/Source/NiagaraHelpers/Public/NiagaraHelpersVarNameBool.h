#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.h"
#include "NiagaraHelpersVarNameBool.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarNameBool : public FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    NIAGARAHELPERS_API FNiagaraHelpersVarNameBool();
};

