#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersVarName.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersVarName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    NIAGARAHELPERS_API FNiagaraHelpersVarName();
};

