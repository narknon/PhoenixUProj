#pragma once
#include "CoreMinimal.h"
#include "AudioMultiSourceAudioEvent.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FAudioMultiSourceAudioEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AkAudioEvent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventName;
    
    PHOENIX_API FAudioMultiSourceAudioEvent();
};

