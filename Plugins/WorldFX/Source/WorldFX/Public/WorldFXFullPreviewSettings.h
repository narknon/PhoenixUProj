#pragma once
#include "CoreMinimal.h"
#include "WorldFXFullPreviewSettings.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXFullPreviewSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAudioPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCascadePreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNiagaraPreview;
    
    WORLDFX_API FWorldFXFullPreviewSettings();
};

