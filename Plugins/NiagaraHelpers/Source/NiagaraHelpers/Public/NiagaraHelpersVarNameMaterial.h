#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.h"
#include "NiagaraHelpersVarNameMaterial.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarNameMaterial : public FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    NIAGARAHELPERS_API FNiagaraHelpersVarNameMaterial();
};

