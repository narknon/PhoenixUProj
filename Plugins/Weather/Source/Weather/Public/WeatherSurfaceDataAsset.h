#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "WeatherDecalSetup.h"
#include "WeatherStormSurfaceParams.h"
#include "WeatherSurfaceCharacterFXSettings.h"
#include "WeatherSurfaceDataAsset.generated.h"

class AWeatherAnimationBlueprint;
class AWeatherCoverageBlueprint;

UCLASS(Blueprintable)
class WEATHER_API UWeatherSurfaceDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDecalSetup Decal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AWeatherAnimationBlueprint> BPWeatherAnimationClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AWeatherCoverageBlueprint> BPWeatherCoverageClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherStormSurfaceParams SurfaceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PermuterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwapRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherSurfaceCharacterFXSettings CharacterFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoWeatherSwap;
    
    UWeatherSurfaceDataAsset();
};

