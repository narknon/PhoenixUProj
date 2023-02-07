#pragma once
#include "CoreMinimal.h"
#include "EFloatMultiChannelNoiseWaveform.h"
#include "FloatMultiChannelNoiseChannel.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FFloatMultiChannelNoiseChannel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Amplitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFloatMultiChannelNoiseWaveform Waveform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    FFloatMultiChannelNoiseChannel();
};

