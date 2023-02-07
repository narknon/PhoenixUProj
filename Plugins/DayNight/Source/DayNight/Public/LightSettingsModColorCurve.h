#pragma once
#include "CoreMinimal.h"
#include "ELightRigCurveLinearColorType.h"
#include "LightSettingsModColorBase.h"
#include "LightSettingsModColorCurve.generated.h"

class UCurveLinearColor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModColorCurve : public ULightSettingsModColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightRigCurveLinearColorType ColorType;
    
    ULightSettingsModColorCurve();
};

