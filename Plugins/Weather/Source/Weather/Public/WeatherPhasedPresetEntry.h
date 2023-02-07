#pragma once
#include "CoreMinimal.h"
#include "WeatherDefinitionName.h"
#include "WeatherPhasedPresetEntry.generated.h"

USTRUCT(BlueprintType)
struct FWeatherPhasedPresetEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Phase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seasons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantChange;
    
    WEATHER_API FWeatherPhasedPresetEntry();
};

