#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeatherPreload.h"
#include "WeatherPreloads.generated.h"

UCLASS(Blueprintable)
class WEATHER_API UWeatherPreloads : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherPreload Preloads;
    
    UWeatherPreloads();
    UFUNCTION(BlueprintCallable)
    void RebuildPreloads();
    
    UFUNCTION(BlueprintCallable)
    void ClearPreloads();
    
};

