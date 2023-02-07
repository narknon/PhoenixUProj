#pragma once
#include "CoreMinimal.h"
#include "MultiBase.h"
#include "MultiVfx.generated.h"

class UNiagaraSystem;
class UParticleSystem;

USTRUCT(BlueprintType)
struct FMultiVfx : public FMultiBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* VFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraVFX;
    
    PHOENIX_API FMultiVfx();
};

