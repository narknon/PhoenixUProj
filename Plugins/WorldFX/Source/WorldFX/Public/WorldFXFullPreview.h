#pragma once
#include "CoreMinimal.h"
#include "WorldFXAudioPreview.h"
#include "WorldFXCascadePreview.h"
#include "WorldFXNiagaraPreview.h"
#include "WorldFXFullPreview.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXFullPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXAudioPreview SFXPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXCascadePreview CascadeFXPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXNiagaraPreview NiagaraFXPreview;
    
    WORLDFX_API FWorldFXFullPreview();
};

