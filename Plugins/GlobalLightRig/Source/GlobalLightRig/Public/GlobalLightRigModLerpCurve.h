#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModLerpControl.h"
#include "GlobalLightRigModLerpCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModLerpCurve : public UGlobalLightRigModLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UGlobalLightRigModLerpCurve();
};

