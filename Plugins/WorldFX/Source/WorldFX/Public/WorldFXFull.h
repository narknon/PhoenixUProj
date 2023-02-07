#pragma once
#include "CoreMinimal.h"
#include "WorldFXAudioEvent.h"
#include "WorldFXCascadeSystem.h"
#include "WorldFXNiagaraSystem.h"
#include "WorldFXFull.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXFull {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXAudioEvent SFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXCascadeSystem CascadeFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXNiagaraSystem NiagaraFX;
    
    WORLDFX_API FWorldFXFull();
};

