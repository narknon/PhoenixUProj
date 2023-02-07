#pragma once
#include "CoreMinimal.h"
#include "WorldFXAudioEvent.h"
#include "WorldFXPreview.h"
#include "WorldFXAudioPreview.generated.h"

class UAkComponent;

USTRUCT(BlueprintType)
struct FWorldFXAudioPreview : public FWorldFXPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    UAkComponent* SFXPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXAudioEvent CurrentFX;
    
    WORLDFX_API FWorldFXAudioPreview();
};

