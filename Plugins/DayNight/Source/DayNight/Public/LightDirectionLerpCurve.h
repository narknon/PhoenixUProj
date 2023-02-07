#pragma once
#include "CoreMinimal.h"
#include "LightDirectionLerpControl.h"
#include "LightDirectionLerpCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightDirectionLerpCurve : public ULightDirectionLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    ULightDirectionLerpCurve();
};

