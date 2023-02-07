#pragma once
#include "CoreMinimal.h"
#include "LightSettingsModFloatBase.h"
#include "LightSettingsModFloatCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModFloatCurve : public ULightSettingsModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    ULightSettingsModFloatCurve();
};

