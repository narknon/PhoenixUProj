#pragma once
#include "CoreMinimal.h"
#include "WeatherDropdownName.generated.h"

USTRUCT(BlueprintType)
struct FWeatherDropdownName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    WEATHER_API FWeatherDropdownName();
};

