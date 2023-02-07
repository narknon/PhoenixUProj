#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersFullVariableListCacheEntry.h"
#include "NiagaraHelpersFullVariableListCacheEntryDynamic.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, NonTransient)
class NIAGARAHELPERS_API UNiagaraHelpersFullVariableListCacheEntryDynamic : public UNiagaraHelpersFullVariableListCacheEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* ProbeComponent;
    
    UNiagaraHelpersFullVariableListCacheEntryDynamic();
protected:
    UFUNCTION(BlueprintCallable)
    void OnFinished();
    
};

