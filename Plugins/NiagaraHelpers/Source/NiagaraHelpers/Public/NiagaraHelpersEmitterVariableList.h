#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVariableList.h"
#include "NiagaraHelpersEmitterVariableList.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersEmitterVariableList : public FNiagaraHelpersVariableList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EmitterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDefaultEnabled;
    
    NIAGARAHELPERS_API FNiagaraHelpersEmitterVariableList();
};

