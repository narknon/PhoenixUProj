#pragma once
#include "CoreMinimal.h"
#include "WindParameters.h"
#include "SceneAction_WeatherLocalWind.h"
#include "SceneAction_WeatherLocalWindParameters.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherLocalWindParameters : public USceneAction_WeatherLocalWind {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParameters WindParameters;
    
    USceneAction_WeatherLocalWindParameters();
};

