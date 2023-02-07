#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NiagaraHelpersInitializerRawRotator.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerRawRotator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Value;
    
    FNiagaraHelpersInitializerRawRotator();
};

