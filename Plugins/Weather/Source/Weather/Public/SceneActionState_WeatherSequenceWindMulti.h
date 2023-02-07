#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "WeatherTimeBase.h"
#include "WindParameters.h"
#include "WindParametersSampleTime.h"
#include "SceneActionState_WeatherSequenceWindMulti.generated.h"

class UWeatherWindDirectionalSourceInstantComponent;
class UWindGustController;

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceWindMulti : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWeatherWindDirectionalSourceInstantComponent> WindSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWindParameters WindParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWindParametersSampleTime SampleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWindGustController* WindGustController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherTimeBase StartWeatherTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bValidParameters;
    
    USceneActionState_WeatherSequenceWindMulti();
};

