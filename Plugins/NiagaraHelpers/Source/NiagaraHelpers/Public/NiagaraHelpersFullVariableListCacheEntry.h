#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "NiagaraHelpersFullVariableList.h"
#include "NiagaraHelpersFullVariableListCacheEntry.generated.h"

class UNiagaraSystem;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, Transient)
class NIAGARAHELPERS_API UNiagaraHelpersFullVariableListCacheEntry : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* System;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersFullVariableList FullVariableList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime CacheTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHaveSetupVariables;
    
    UNiagaraHelpersFullVariableListCacheEntry();
};

