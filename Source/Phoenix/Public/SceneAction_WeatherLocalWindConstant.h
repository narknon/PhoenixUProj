#pragma once
#include "CoreMinimal.h"
#include "WindParametersInstant.h"
#include "SceneAction_WeatherLocalWind.h"
#include "SceneAction_WeatherLocalWindConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherLocalWindConstant : public USceneAction_WeatherLocalWind {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParametersInstant WindParameters;
    
    USceneAction_WeatherLocalWindConstant();
};

