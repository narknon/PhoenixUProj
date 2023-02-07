#pragma once
#include "CoreMinimal.h"
#include "FXEnd.h"
#include "MultiFX2End_NiagraVfx.generated.h"

class UNiagaraSystem;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2End_NiagraVfx : public UFXEnd {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
public:
    UMultiFX2End_NiagraVfx();
};

