#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalarSingleParam.h"
#include "FXAutoTriggerScalarCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarCurve : public UFXAutoTriggerScalarSingleParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UFXAutoTriggerScalarCurve();
};

