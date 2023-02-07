#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsScalarName.h"
#include "SceneAction_WeatherSequenceEnvGlobal.h"
#include "SceneAction_WeatherSequenceEnvGlobalScalar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceEnvGlobalScalar : public USceneAction_WeatherSequenceEnvGlobal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsScalarName VariableName;
    
    USceneAction_WeatherSequenceEnvGlobalScalar();
};

