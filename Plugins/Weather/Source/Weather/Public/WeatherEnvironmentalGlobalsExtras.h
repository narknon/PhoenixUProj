#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsExtraVariables.h"
#include "EnvironmentalGlobalsUnsetExtraVariables.h"
#include "WeatherEnvironmentalGlobalsExtras.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherEnvironmentalGlobalsExtras {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsExtraVariables StartState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsExtraVariables CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsUnsetExtraVariables UNSET;
    
    FWeatherEnvironmentalGlobalsExtras();
};

