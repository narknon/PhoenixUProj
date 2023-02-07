#pragma once
#include "CoreMinimal.h"
#include "DayNightLightSkyAtmosphereComputeParams.h"
#include "EDayNightLightControllerOp.h"
#include "SceneActionDayNightLightControllerSettings.h"
#include "SceneRigDayNightAtmosphereLightControllerSettings.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class USceneRigDayNightAtmosphereLightControllerSettings : public USceneActionDayNightLightControllerSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightSkyAtmosphereComputeParams SkyParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseIntensityFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Desaturation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightLightControllerOp ColorOp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightLightControllerOp IntensityOp;
    
    USceneRigDayNightAtmosphereLightControllerSettings();
};

