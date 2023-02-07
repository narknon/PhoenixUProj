#pragma once
#include "CoreMinimal.h"
#include "WeatherSequenceInfo.generated.h"

class UWeatherSequence;

USTRUCT(BlueprintType)
struct FWeatherSequenceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWeatherSequence> Sequence;
    
    WEATHER_API FWeatherSequenceInfo();
};

