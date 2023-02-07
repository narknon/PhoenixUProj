#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersEmitterVariableList.h"
#include "NiagaraHelpersVariableList.h"
#include "NiagaraHelpersVariableValueStore.h"
#include "NiagaraHelpersFullVariableList.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersFullVariableList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersVariableList UserVariables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersVariableList SystemVariables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraHelpersEmitterVariableList> EmitterVariables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersVariableValueStore DefaultValues;
    
    NIAGARAHELPERS_API FNiagaraHelpersFullVariableList();
};

