#pragma once
#include "CoreMinimal.h"
#include "FullWeatherState.h"
#include "WeatherIndoors.h"
#include "WeatherTime.h"
#include "WeatherWindDirectionalSourceStack.h"
#include "WindDetails.h"
#include "WindParametersInstant.h"
#include "WorldWindOffset.h"
#include "WeatherActionContext.generated.h"

class UWeatherOrphanComponent;
class UWeatherWindDirectionalSourceComponentBase;

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherActionContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullWeatherState PriorState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullWeatherState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherTime CurrentTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherWindDirectionalSourceComponentBase*> WindSources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParametersInstant Wind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindDetails WindDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldWindOffset WindOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherIndoors WeatherIndoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWeatherOrphanComponent*> LightingOrphans;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherWindDirectionalSourceStack LegacyWindSourceStack;
    
    FWeatherActionContext();
};

