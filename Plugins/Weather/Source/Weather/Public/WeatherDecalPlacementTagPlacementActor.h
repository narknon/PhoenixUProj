#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalPlacement.h"
#include "WeatherDecalPlacementTagPlacementActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalPlacementTagPlacementActor : public UWeatherDecalPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DecalTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailOnNotFound;
    
    UWeatherDecalPlacementTagPlacementActor();
};

