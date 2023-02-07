#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherMaster.generated.h"

class URenderSettingsComponent;
class UWeatherMasterComponent;
class UWindDirectionalSourceComponent;

UCLASS(Blueprintable)
class WEATHER_API AWeatherMaster : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeatherMasterComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWindDirectionalSourceComponent* DebugWindComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsComponent* OvercastVolume;
    
    AWeatherMaster();
    UFUNCTION(BlueprintCallable)
    void NextSequence();
    
};

