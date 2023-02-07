#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeatherDecalPlacement.h"
#include "WeatherDecalPlacementLegacy.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalPlacementLegacy : public UWeatherDecalPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    UWeatherDecalPlacementLegacy();
};

