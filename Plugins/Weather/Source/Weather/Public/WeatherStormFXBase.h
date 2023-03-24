#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherStormState.h"
#include "WeatherStormFXBase.generated.h"

class UWeatherStorm;

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherStormFXBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWeatherStorm* WeatherStorm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverrideActivationDistanceMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseOverrideActivationDistanceMeters;
    
    AWeatherStormFXBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStormStart(FWeatherStormState StormState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStormEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsStorming(bool& bStorming) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetStormState(FWeatherStormState& StormState, bool& bStorming) const;
    
};

