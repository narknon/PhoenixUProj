#pragma once
#include "CoreMinimal.h"
#include "WeatherStormTypeFXSettingsState.generated.h"

class UAkAudioEvent;
class UNiagaraComponent;

USTRUCT(BlueprintType)
struct FWeatherStormTypeFXSettingsState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraVFXComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SoundFXHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EndSoundFX;
    
    WEATHER_API FWeatherStormTypeFXSettingsState();
};

