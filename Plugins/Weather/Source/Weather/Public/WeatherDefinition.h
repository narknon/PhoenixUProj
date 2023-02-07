#pragma once
#include "CoreMinimal.h"
#include "CloudDefinitionName.h"
#include "FogDefinitionName.h"
#include "WindDefinitionName.h"
#include "WeatherDefinition.generated.h"

USTRUCT(BlueprintType)
struct FWeatherDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCloudDefinitionName Clouds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFogDefinitionName Fog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindDefinitionName Wind;
    
    WEATHER_API FWeatherDefinition();
};

