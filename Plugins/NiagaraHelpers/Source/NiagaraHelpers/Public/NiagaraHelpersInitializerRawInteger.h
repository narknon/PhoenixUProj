#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializerRawInteger.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerRawInteger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    FNiagaraHelpersInitializerRawInteger();
};

