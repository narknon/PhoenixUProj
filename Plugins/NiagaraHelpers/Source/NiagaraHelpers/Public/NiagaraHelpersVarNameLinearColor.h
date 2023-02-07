#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.h"
#include "NiagaraHelpersVarNameLinearColor.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarNameLinearColor : public FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    NIAGARAHELPERS_API FNiagaraHelpersVarNameLinearColor();
};

