#pragma once
#include "CoreMinimal.h"
#include "LightSettingsLerpControl.h"
#include "LightSettingsLerpCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsLerpCurve : public ULightSettingsLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    ULightSettingsLerpCurve();
};

