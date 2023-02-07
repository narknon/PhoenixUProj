#pragma once
#include "CoreMinimal.h"
#include "DayNightLightControllerDirectionalBoost.h"
#include "EDayNightLightControllerOp.h"
#include "SceneActionDayNightLightControllerSettings.h"
#include "SceneRigDayNightCurveLightControllerSettings.generated.h"

class UCurveFloat;
class UCurveLinearColor;

UCLASS(Blueprintable)
class USceneRigDayNightCurveLightControllerSettings : public USceneActionDayNightLightControllerSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Desaturation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightControllerDirectionalBoost DirectionalBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDirectionalBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightLightControllerOp ColorOp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightLightControllerOp IntensityOp;
    
    USceneRigDayNightCurveLightControllerSettings();
};

