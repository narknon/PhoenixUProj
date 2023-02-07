#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializerInteger.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerInteger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    FNiagaraHelpersInitializerInteger();
};

