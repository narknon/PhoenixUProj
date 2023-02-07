#pragma once
#include "CoreMinimal.h"
#include "WeatherWindDirectionalSourceStack.generated.h"

class UWeatherWindDirectionalSourceComponentBase;

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherWindDirectionalSourceStack {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UWeatherWindDirectionalSourceComponentBase>> Stack;
    
    FWeatherWindDirectionalSourceStack();
};

