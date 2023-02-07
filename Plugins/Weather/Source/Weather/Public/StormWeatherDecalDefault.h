#pragma once
#include "CoreMinimal.h"
#include "StormWeatherDecal.h"
#include "Templates/SubclassOf.h"
#include "WeatherDecalSetup.h"
#include "WeatherStormSurfaceParams.h"
#include "StormWeatherDecalDefault.generated.h"

class AWeatherAnimationBlueprint;
class AWeatherCoverageBlueprint;
class UWeatherDecalSettings;
class UWeatherDecalUpdate;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UStormWeatherDecalDefault : public UStormWeatherDecal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDecalSetup Setup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AWeatherAnimationBlueprint> WeatherAnimationClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AWeatherCoverageBlueprint> WeatherCoverageClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherStormSurfaceParams SurfaceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSettings*> ExtraSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalUpdate*> Updates;
    
    UStormWeatherDecalDefault();
};

