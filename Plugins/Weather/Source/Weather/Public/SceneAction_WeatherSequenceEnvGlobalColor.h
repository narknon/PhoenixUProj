#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsVectorOrColorName.h"
#include "SceneAction_WeatherSequenceEnvGlobal.h"
#include "SceneAction_WeatherSequenceEnvGlobalColor.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceEnvGlobalColor : public USceneAction_WeatherSequenceEnvGlobal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsVectorOrColorName VariableName;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLerpWithHSV;
    
    USceneAction_WeatherSequenceEnvGlobalColor();
};

