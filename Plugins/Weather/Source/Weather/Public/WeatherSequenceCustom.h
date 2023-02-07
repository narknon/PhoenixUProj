#pragma once
#include "CoreMinimal.h"
#include "WeatherSequenceInfoWithProbability.h"
#include "WeatherSequenceCustom.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSequenceCustom {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfoWithProbability> Sequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlaybackScale;
    
    WEATHER_API FWeatherSequenceCustom();
};

