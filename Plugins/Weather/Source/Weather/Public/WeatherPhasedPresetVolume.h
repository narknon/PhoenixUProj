#pragma once
#include "CoreMinimal.h"
#include "WeatherPhasedPresetEntry.h"
#include "WeatherPresetVolumeBase.h"
#include "WeatherSeasonsFilter.h"
#include "WeatherPhasedPresetVolume.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherPhasedPresetVolume : public AWeatherPresetVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherPhasedPresetEntry> Presets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActivePhase;
    
    AWeatherPhasedPresetVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetActiveWeatherPhase(FName PhaseName, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsValidActiveWeatherPhaseCurrentSeason(FName PhaseName, bool& bValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsValidActiveWeatherPhase(FName PhaseName, FWeatherSeasonsFilter& ValidSeasons);
    
};

