#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfaceCharacterFXStateResetType.h"
#include "WeatherSurfaceCharacterFXStateReset.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSurfaceCharacterFXStateReset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceCharacterFXStateResetType IndoorsReset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceCharacterFXStateResetType OutdoorsReset;
    
    WEATHER_API FWeatherSurfaceCharacterFXStateReset();
};

