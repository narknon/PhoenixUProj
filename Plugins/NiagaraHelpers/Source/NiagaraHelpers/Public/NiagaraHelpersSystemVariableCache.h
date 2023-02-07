#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersSystemVariableCache.generated.h"

class UNiagaraHelpersFullVariableListCacheEntry;
class UNiagaraSystem;

USTRUCT(BlueprintType)
struct FNiagaraHelpersSystemVariableCache {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UNiagaraSystem>, UNiagaraHelpersFullVariableListCacheEntry*> SystemMap;
    
    NIAGARAHELPERS_API FNiagaraHelpersSystemVariableCache();
};

