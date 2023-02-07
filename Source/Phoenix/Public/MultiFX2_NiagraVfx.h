#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_NiagraBase.h"
#include "MultiFX2_NiagraVfx.generated.h"

class UNiagaraSystem;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_NiagraVfx : public UMultiFX2_NiagraBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDeactivate;
    
public:
    UMultiFX2_NiagraVfx();
};

