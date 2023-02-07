#pragma once
#include "CoreMinimal.h"
#include "MultiVfx.h"
#include "MultiVfxSfx.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FMultiVfxSfx : public FMultiVfx {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* SFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EndSfx;
    
    PHOENIX_API FMultiVfxSfx();
};

