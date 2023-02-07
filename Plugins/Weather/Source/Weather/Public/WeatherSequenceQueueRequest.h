#pragma once
#include "CoreMinimal.h"
#include "WeatherSequenceOrigin.h"
#include "WeatherSequenceQueueRequest.generated.h"

class UWeatherSequence;

USTRUCT(BlueprintType)
struct FWeatherSequenceQueueRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWeatherSequence> Asset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherSequenceOrigin Origin;
    
    WEATHER_API FWeatherSequenceQueueRequest();
};

