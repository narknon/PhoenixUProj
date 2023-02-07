#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParametersOverride.h"
#include "SceneAction_WeatherSequenceFog.h"
#include "SceneAction_WeatherSequenceFogOverrideParams.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceFogOverrideParams : public USceneAction_WeatherSequenceFog {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParametersOverride Fog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollowCamera;
    
    USceneAction_WeatherSequenceFogOverrideParams();
};

