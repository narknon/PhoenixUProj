#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalUpdate.h"
#include "WeatherDecalUpdateSeasonsPhases.generated.h"

class UWeatherDecalSettings;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalUpdateSeasonsPhases : public UWeatherDecalUpdate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSettings*> FallPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSettings*> WinterPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSettings*> SpringPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSettings*> SummerPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSeasonOverride;
    
    UWeatherDecalUpdateSeasonsPhases();
};

