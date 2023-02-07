#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherGeneric.h"
#include "SceneAction_WeatherPrecipitationPercentage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherPrecipitationPercentage : public USceneAction_WeatherGeneric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrecipitationPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrecipitationFadeTime;
    
    USceneAction_WeatherPrecipitationPercentage();
};

