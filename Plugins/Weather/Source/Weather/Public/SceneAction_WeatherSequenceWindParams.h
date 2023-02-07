#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceWind.h"
#include "WindParameters.h"
#include "WindParametersSampleTime.h"
#include "SceneAction_WeatherSequenceWindParams.generated.h"

class UWindGustController;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceWindParams : public USceneAction_WeatherSequenceWind {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParameters Wind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindGustController* WindGustController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParametersSampleTime SampleTime;
    
    USceneAction_WeatherSequenceWindParams();
};

