#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializerBool.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Value;
    
    FNiagaraHelpersInitializerBool();
};

