#pragma once
#include "CoreMinimal.h"
#include "MultiBase.h"
#include "MultiSfx.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FMultiSfx : public FMultiBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* SFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EndSfx;
    
    PHOENIX_API FMultiSfx();
};

