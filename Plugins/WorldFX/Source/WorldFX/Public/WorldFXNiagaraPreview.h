#pragma once
#include "CoreMinimal.h"
#include "WorldFXNiagaraSystem.h"
#include "WorldFXPreview.h"
#include "WorldFXNiagaraPreview.generated.h"

class UNiagaraComponent;

USTRUCT(BlueprintType)
struct FWorldFXNiagaraPreview : public FWorldFXPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraFXPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXNiagaraSystem CurrentFX;
    
    WORLDFX_API FWorldFXNiagaraPreview();
};

