#pragma once
#include "CoreMinimal.h"
#include "WeatherOverrideStackEntry.h"
#include "WeatherOverrideStack.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherOverrideStack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherOverrideStackEntry> Presets;
    
    FWeatherOverrideStack();
};

