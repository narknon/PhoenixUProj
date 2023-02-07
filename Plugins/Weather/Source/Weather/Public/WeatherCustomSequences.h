#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeatherSequenceCustom.h"
#include "WeatherCustomSequences.generated.h"

UCLASS(Blueprintable)
class WEATHER_API UWeatherCustomSequences : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceCustom> CustomSequences;
    
    UWeatherCustomSequences();
};

