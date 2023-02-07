#pragma once
#include "CoreMinimal.h"
#include "WeatherPreload.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FWeatherPreload {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> Preloads;
    
    WEATHER_API FWeatherPreload();
};

