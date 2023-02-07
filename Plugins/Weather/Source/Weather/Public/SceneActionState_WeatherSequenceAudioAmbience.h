#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceAudioAmbience.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceAudioAmbience : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SoundHandle;
    
    USceneActionState_WeatherSequenceAudioAmbience();
};

