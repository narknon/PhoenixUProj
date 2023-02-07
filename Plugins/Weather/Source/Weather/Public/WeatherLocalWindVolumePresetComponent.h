#pragma once
#include "CoreMinimal.h"
#include "WeatherLocalWindComponent.h"
#include "WindDefinitionName.h"
#include "WeatherLocalWindVolumePresetComponent.generated.h"

class UWindParams;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UDEPRECATED_WeatherLocalWindVolumePresetComponent : public UDEPRECATED_WeatherLocalWindComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindDefinitionName Preset;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWindParams> PresetPtr;
    
public:
    UDEPRECATED_WeatherLocalWindVolumePresetComponent();
};

