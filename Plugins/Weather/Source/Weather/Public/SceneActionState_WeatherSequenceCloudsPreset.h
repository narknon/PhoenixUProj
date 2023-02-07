#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequenceAuto.h"
#include "SceneActionState_WeatherSequenceCloudsPreset.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceCloudsPreset : public USceneActionState_WeatherSequenceAuto {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LatchedBlendIn;
    
public:
    USceneActionState_WeatherSequenceCloudsPreset();
};

