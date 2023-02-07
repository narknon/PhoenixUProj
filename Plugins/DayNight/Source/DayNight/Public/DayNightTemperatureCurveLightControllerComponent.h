#pragma once
#include "CoreMinimal.h"
#include "DayNightLightControllerComponent.h"
#include "DayNightLightControllerDirectionalBoost.h"
#include "EDayNightLightControllerOp.h"
#include "DayNightTemperatureCurveLightControllerComponent.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UDayNightTemperatureCurveLightControllerComponent : public UDayNightLightControllerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ColorTemp;
    
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAccurateColorTemp;
    
    UDayNightTemperatureCurveLightControllerComponent();
};

