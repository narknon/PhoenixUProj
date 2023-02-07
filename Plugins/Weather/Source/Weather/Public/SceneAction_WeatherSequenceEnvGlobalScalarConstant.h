#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceEnvGlobalScalar.h"
#include "SceneAction_WeatherSequenceEnvGlobalScalarConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceEnvGlobalScalarConstant : public USceneAction_WeatherSequenceEnvGlobalScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    USceneAction_WeatherSequenceEnvGlobalScalarConstant();
};

