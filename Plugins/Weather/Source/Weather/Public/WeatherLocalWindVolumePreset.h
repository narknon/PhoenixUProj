#pragma once
#include "CoreMinimal.h"
#include "WeatherLocalWindVolume.h"
#include "WindDefinitionName.h"
#include "WeatherLocalWindVolumePreset.generated.h"

class UWindParams;

UCLASS(Blueprintable)
class WEATHER_API ADEPRECATED_WeatherLocalWindVolumePreset : public ADEPRECATED_WeatherLocalWindVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindDefinitionName Preset;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWindParams> PresetPtr;
    
public:
    ADEPRECATED_WeatherLocalWindVolumePreset();
};

