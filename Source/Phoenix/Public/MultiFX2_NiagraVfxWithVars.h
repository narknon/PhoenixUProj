#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_NiagraBase.h"
#include "MultiFX2_NiagraVfxWithVars.generated.h"

class UNiagaraSystemWithVars;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_NiagraVfxWithVars : public UMultiFX2_NiagraBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystemWithVars* NiagaraVfxWithVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDeactivate;
    
public:
    UMultiFX2_NiagraVfxWithVars();
};

