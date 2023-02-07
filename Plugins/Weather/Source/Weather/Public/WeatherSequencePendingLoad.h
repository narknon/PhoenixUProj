#pragma once
#include "CoreMinimal.h"
#include "LiveWeatherSequenceInfo.h"
#include "WeatherSequencePendingLoad.generated.h"

class UWeatherSequence;

UCLASS(Blueprintable, NonTransient)
class WEATHER_API UWeatherSequencePendingLoad : public ULiveWeatherSequenceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWeatherSequence> Asset;
    
    UWeatherSequencePendingLoad();
};

