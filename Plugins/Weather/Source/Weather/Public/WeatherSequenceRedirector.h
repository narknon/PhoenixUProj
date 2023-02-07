#pragma once
#include "CoreMinimal.h"
#include "WeatherSequenceNoRedirectorsName.h"
#include "WeatherSequenceRedirector.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSequenceRedirector {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OldName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherSequenceNoRedirectorsName RedirectTo;
    
    WEATHER_API FWeatherSequenceRedirector();
};

