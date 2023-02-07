#pragma once
#include "CoreMinimal.h"
#include "WorldFXAudioEventRTPC.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXAudioEventRTPC {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpolationTime;
    
    FWorldFXAudioEventRTPC();
};

