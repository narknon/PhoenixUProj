#pragma once
#include "CoreMinimal.h"
#include "DayNightLightControllerComponent.h"
#include "DayNightLightControllerDirectionalBoost.h"
#include "EDayNightLightControllerOp.h"
#include "DayNightCurveLightControllerComponent.generated.h"

class UCurveFloat;
class UCurveLinearColor;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UDayNightCurveLightControllerComponent : public UDayNightLightControllerComponent {
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
    
    UDayNightCurveLightControllerComponent();
};

