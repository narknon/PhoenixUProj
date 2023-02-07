#pragma once
#include "CoreMinimal.h"
#include "EWeatherSequenceProbability.h"
#include "WeatherSequenceInfo.h"
#include "WeatherSequenceInfoWithProbability.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSequenceInfoWithProbability : public FWeatherSequenceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSequenceProbability Probability;
    
    WEATHER_API FWeatherSequenceInfoWithProbability();
};

