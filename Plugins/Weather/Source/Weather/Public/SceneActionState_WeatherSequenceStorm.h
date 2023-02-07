#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceStorm.generated.h"

class UWeatherSurfaceDataAsset;

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceStorm : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeatherSurfaceDataAsset* Precipitation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKickedOff;
    
    USceneActionState_WeatherSequenceStorm();
};

