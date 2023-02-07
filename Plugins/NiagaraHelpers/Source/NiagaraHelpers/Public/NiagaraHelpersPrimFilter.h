#pragma once
#include "CoreMinimal.h"
#include "ENiagaraHelpersPrimMatchMode.h"
#include "ENiagaraHelpersPrimRule.h"
#include "NiagaraHelpersPrimFilter.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraHelpersPrimFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Primitives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENiagaraHelpersPrimRule Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENiagaraHelpersPrimMatchMode MatchMode;
    
    NIAGARAHELPERS_API FNiagaraHelpersPrimFilter();
};

