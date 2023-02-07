#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParameters.h"
#include "SceneAction_WeatherSequenceFog.h"
#include "SceneAction_WeatherSequenceFogParams.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceFogParams : public USceneAction_WeatherSequenceFog {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParameters Fog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollowCamera;
    
    USceneAction_WeatherSequenceFogParams();
};

