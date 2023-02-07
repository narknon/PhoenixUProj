#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherGeneric.h"
#include "WeatherSurfaceCharacterFXStateReset.h"
#include "SceneAction_WeatherAccumulationReset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WeatherAccumulationReset : public USceneAction_WeatherGeneric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherSurfaceCharacterFXStateReset StateReset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrecipitationPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrecipitationFadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWindSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetMaxWindSpeed;
    
    USceneAction_WeatherAccumulationReset();
};

