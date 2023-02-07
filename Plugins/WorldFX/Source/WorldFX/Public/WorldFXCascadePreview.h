#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeSystem.h"
#include "WorldFXPreview.h"
#include "WorldFXCascadePreview.generated.h"

class UParticleSystemComponent;

USTRUCT(BlueprintType)
struct FWorldFXCascadePreview : public FWorldFXPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* CascadeFXPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXCascadeSystem CurrentFX;
    
    WORLDFX_API FWorldFXCascadePreview();
};

