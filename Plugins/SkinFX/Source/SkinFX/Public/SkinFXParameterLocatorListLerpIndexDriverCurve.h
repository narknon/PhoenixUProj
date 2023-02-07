#pragma once
#include "CoreMinimal.h"
#include "SkinFXParameterLocatorListLerpIndexDriver.h"
#include "SkinFXParameterLocatorListLerpIndexDriverCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterLocatorListLerpIndexDriverCurve : public USkinFXParameterLocatorListLerpIndexDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHermite;
    
    USkinFXParameterLocatorListLerpIndexDriverCurve();
};

