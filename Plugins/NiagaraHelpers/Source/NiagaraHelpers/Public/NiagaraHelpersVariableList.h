#pragma once
#include "CoreMinimal.h"
#include "NiagaraTypes.h"
#include "NiagaraHelpersVariableList.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVariableList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraVariable> Variables;
    
    NIAGARAHELPERS_API FNiagaraHelpersVariableList();
};

